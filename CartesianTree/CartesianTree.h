//  Декартово дерево

#pragma once

#include<iostream>
#include "CartesianTreeNode.h"

class CartesianTree {
private: 
	CartesianTreeNode* HEAD;

public:
	CartesianTree() : HEAD(NULL){}

	//  Должен быть деструктор

	void insert(const int& _val) {
		CartesianTreeNode* node = new CartesianTreeNode(_val);
		insert_main(HEAD, node);
	}

	void remove(int _val) {
		remove_main(HEAD, _val);
	}

	void print_tree_horizontal() const {  //  Печать дерева
		print_tree_hor_main(HEAD, 0);
	}

	void print_tree_vertical() const {  //  Печать дерева
		print_tree_ver_main(HEAD, 0);
	}

	CartesianTreeNode* search(int _val) const {
		CartesianTreeNode* result = search_main(HEAD, _val);
		return result;
	}

private:

	//  Разделеяет дерево на два поддерева, в левом все значения меньшие _val, в правом большие
	void split(CartesianTreeNode* cart_tree, int _val, CartesianTreeNode *&left_tree, CartesianTreeNode *&right_tree) {
		if(cart_tree == nullptr) {
			left_tree, right_tree = nullptr;
		} else {
			if(cart_tree->value > _val) {
				split(cart_tree->left, _val, left_tree, cart_tree->left);
				right_tree = cart_tree;
			} else {
				split(cart_tree->right, _val, cart_tree->right, right_tree);
				left_tree = cart_tree;
			}
		}
	}
//  Функция распределения
	void insert_main(CartesianTreeNode *&cart_tree, CartesianTreeNode* cart_node) {
		if(cart_tree == nullptr) { //  Если пустой узел, то создаем
			cart_tree = cart_node;
			return;
		} else {
			if((cart_tree)->prior < cart_node->prior) {
				split(cart_tree, cart_node->value, (cart_node->left), (cart_node->right));
				cart_tree = cart_node;
			} else {
				if(cart_node->value < (cart_tree)->value) {
					insert_main(((cart_tree)->left), cart_node);
				} else {
					insert_main(((cart_tree)->right), cart_node);
				}
			}
		}
	}

	// Принимает два дерева, с ключами в первом меньше равными ключам второго, и строит общее 
	void merge(CartesianTreeNode *&cart_tree, CartesianTreeNode* left_tree, CartesianTreeNode* right_tree) {
		if((left_tree == nullptr) || (right_tree == nullptr)) {
			cart_tree = left_tree ? left_tree : right_tree;
		} else {
			if(left_tree->prior > right_tree->prior) {
				merge(left_tree->right, left_tree->right, right_tree);
				cart_tree = left_tree;
			} else {
				merge(right_tree->right, left_tree, right_tree->left);
				cart_tree = right_tree;
			}
		}
	}

	void remove_main(CartesianTreeNode *&cart_tree,int _val) {
		if(cart_tree->value == _val) {
			merge(cart_tree, cart_tree->left, cart_tree->right);
		} else {
			remove_main(_val < cart_tree->value ? cart_tree->left : cart_tree->right, _val);
		}
	}

	CartesianTreeNode* search_main(CartesianTreeNode* cart_tree, int _val) const{ //  Поиск
	 	CartesianTreeNode* res;
		if((cart_tree)->value == _val) { //  Если пустой узел, то создаем
			res = cart_tree;
		} else { 
			if((cart_tree)->value > _val) {  //  Если значение меньше, то в левое поддерево
				res = search_main(((cart_tree)->left), _val);
			} else {
				if((cart_tree)->value < _val) {  //  Если значение больше, то в правое поддерево
					res = search_main(((cart_tree)->right), _val);
				}
			}
		}
		return res;
	}
	
	void print_tree_hor_main(CartesianTreeNode* cart_tree, unsigned int _spaces) const {  //  Основная печать дерева
		while(cart_tree != NULL) {
			print_tree_hor_main(cart_tree->right, _spaces + 5);

			for(int i = 1; i < _spaces; i++)
				std::cout<<" ";

			std::cout<<cart_tree->value<<" : "<<floor(cart_tree->prior * 1000)/1000<<std::endl;

			cart_tree = cart_tree->left;

			_spaces += 5;
		}
	}

	void print_tree_ver_main(CartesianTreeNode* cart_tree, unsigned int _level) const { //  Работает
	    if(cart_tree)
	    {
	        print_tree_ver_main(cart_tree->right, _level+ 1);
	        for(int i = 0; i < _level; i++) 
	        	std::cout<<"   ";
	        std::cout << cart_tree->value <<" : "<<floor(cart_tree->prior * 1000)/1000 <<std::endl;
	        print_tree_ver_main(cart_tree->left,_level + 1);
	    }
	}
};