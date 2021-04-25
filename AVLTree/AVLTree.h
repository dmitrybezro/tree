// АВЛ дерево
#pragma once

#include<iostream>
#include "AVLTreeNode.h"

class AVLTree {
// дописать вставку
private:
	AVLTreeNode* HEAD;

public:
	AVLTree() : HEAD(nullptr) {}

	void insert(int _val) {
		HEAD = insert_main(HEAD, _val);
	}

	void remove(int _val) {
		HEAD = remove_main(HEAD, _val);
	}

	AVLTreeNode* search(int _val) const {
		return search_main(HEAD, _val);
	}

	void print_tree_horizontal() const {  //  Печать дерева
		print_tree_hor_main(HEAD, 2);
	}

	int get_head() {
		return HEAD->value;
	}

	void crawl() const {  //  Обход дерева. Чтобы был. Хз зачем.
		crawl_main(HEAD);
		//std::cout<<std::endl;
	} 

private:

	//  Вернуть высоту
	unsigned char get_height(AVLTreeNode* avl_tree) {
		return avl_tree ? avl_tree->height : 0;
	}

	//  Возвращает баланс фактор ( разница высот левого и правого поддеревьев)
	int balance_factor(AVLTreeNode* avl_tree){
		return (get_height(avl_tree->right) - get_height(avl_tree->left));
	}

	//  Восстанавливает правильное значение высоты в узле
	void correct_height(AVLTreeNode* avl_tree) {
		unsigned char height1 = get_height(avl_tree->left);
		unsigned char height2 = get_height(avl_tree->right);
		avl_tree->height = (height1 > height2 ? height1 : height2) + 1;
	}

	//  Правый поворот вокруг avl_tree
	AVLTreeNode* right_turn(AVLTreeNode* avl_tree) {
		AVLTreeNode* node = avl_tree->left;
		avl_tree->left = node->right;
		node->right = avl_tree;

		correct_height(avl_tree);
		correct_height(node);

		return node;
	}

	//  Левый поворот вокруг avl_tree
	AVLTreeNode* left_turn(AVLTreeNode* avl_tree) {
		AVLTreeNode* node = avl_tree->right;
		avl_tree->right = node->left;
		node->left = avl_tree;

		correct_height(avl_tree);
		correct_height(node);

		return node;
	}

	//  Балансировка дерева
	AVLTreeNode* balance ( AVLTreeNode* avl_tree) {

		correct_height(avl_tree);

		if(balance_factor(avl_tree) == 2) {
			if(balance_factor(avl_tree->right) < 0)
				avl_tree->right = right_turn(avl_tree->right);
			return left_turn(avl_tree);

		} 
		
		if(balance_factor(avl_tree) == -2) {
			if(balance_factor(avl_tree->left) > 0)
				avl_tree->left = left_turn(avl_tree->left);
			return right_turn(avl_tree);
		}
		return avl_tree;
	}

		//  Балансировка дерева
	AVLTreeNode* balance_tree ( AVLTreeNode* avl_tree) {

		correct_height(avl_tree);

		if(balance_factor(avl_tree) == 2) {
			if(balance_factor(avl_tree->right) < 0)
				avl_tree->right = right_turn(avl_tree->right);
			return left_turn(avl_tree);

		} 
		
		if(balance_factor(avl_tree) == -2) {
			if(balance_factor(avl_tree->left) > 0)
				avl_tree->left = left_turn(avl_tree->left);
			return right_turn(avl_tree);
		}
		return avl_tree;
	}

	//  Основная работа вставки
	AVLTreeNode* insert_main(AVLTreeNode* avl_tree, int _val) {
		if(avl_tree == nullptr) { //  Если пустой узел, то создаем
			return new AVLTreeNode(_val);
		} else {
			if(_val < (avl_tree)->value) {
				(avl_tree)->left = insert_main((avl_tree)->left, _val);
			} else {
				(avl_tree)->right = insert_main((avl_tree)->right, _val);
			}
			return balance(avl_tree);
		}
	}

	//  Печать дерева
	void print_tree_hor_main(AVLTreeNode* avl_tree, unsigned int _level) const {
	    if(avl_tree)
	    {
	        print_tree_hor_main(avl_tree->right, _level+ 2);
	        for(int i = 0; i < _level; i++) 
	        	std::cout<<"   ";
	        std::cout << avl_tree->value << std::endl;
	        print_tree_hor_main(avl_tree->left,_level + 2);
	    }
	}


	//  Поиск минимального элемента в поддереве
	AVLTreeNode* find_min_elem(AVLTreeNode* avl_tree) {
		return avl_tree->left ? find_min_elem(avl_tree->left) : avl_tree;
	}

	//  Удаление узла с минимальным значением из дерева
	AVLTreeNode* delete_min_elem(AVLTreeNode* avl_tree) {
		if(avl_tree->left == 0) {
			return avl_tree->right;
		}
		avl_tree->left = delete_min_elem(avl_tree->left);
		return balance(avl_tree);
	}

	//  Основная работа удаления
	AVLTreeNode* remove_main(AVLTreeNode* avl_tree, int _val) {
		if(avl_tree == nullptr)
			return nullptr;
		if(_val > avl_tree->value) {
			avl_tree->left = remove_main(avl_tree->left, _val);
		} else {
			if (_val < avl_tree->value) {
				avl_tree->right = remove_main(avl_tree->right, _val);
			} else { //  Если нашли равенство элементу
				AVLTreeNode* node1 = avl_tree->left;  //  Запоминаем поддеревья
				AVLTreeNode* node2 = avl_tree->right;
				delete avl_tree;
				if(!node2)
					return node1;
				AVLTreeNode* min = find_min_elem(node2);
				min->right = delete_min_elem(node2);
				min->left = node1;
				return balance_tree(min);
			}
		}

		return balance(avl_tree);

	}
	//  Поиск
	AVLTreeNode* search_main(AVLTreeNode* avl_tree, int _val) const{ 
	 	AVLTreeNode* res;
		if((avl_tree)->value == _val) { //  Если 
			res = avl_tree;
		} else { 
			if((avl_tree)->value > _val) {  //  Если значение меньше, то в левое поддерево
				res = search_main(((avl_tree)->left), _val);
			} else {
				if((avl_tree)->value < _val) {  //  Если значение больше, то в правое поддерево
					res = search_main(((avl_tree)->right), _val);
				}
			}
		}
		return res;
	}

		void crawl_main(AVLTreeNode* bin_tree) const {  //  Основной обход дерева
		if(bin_tree != NULL) {
			//std::cout<<bin_tree->value<<"  ";
			crawl_main(bin_tree->left);  //  Сначала по левому поддереву
			crawl_main(bin_tree->right);  //  Потом по правому
		}
	}
};