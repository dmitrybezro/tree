#pragma once
#include<cmath>
#include<iostream>
#include"BinaryTreeNode.h"


class BinaryTree {

	BinaryTreeNode* HEAD;

public:
	BinaryTree():HEAD(NULL){}
	~BinaryTree() {
		destruct(HEAD);
	}
	void insert(const int& _val) { // Вставка
		insert_main(&HEAD, _val);
	}

	void remove(const int& _val) {  //  Удаление узла по значению
		remove_main(&HEAD, _val);
	}

	int depth() const {  //  Глубина дерева
		return depth_main(HEAD);
	}

	void crawl() const {  //  Обход дерева. Чтобы был. Хз зачем.
		crawl_main(HEAD);
		std::cout<<std::endl;
	} 

	void print_tree() const {  //  Печать дерева
		print_tree_main(HEAD, 0);
		std::cout<<"-----------------------"<<std::endl;

	}

	int min_elem() const {  //  Поиск минимального элемента
		return min_elem_main(HEAD);
	}

	int max_elem() const {  //  Поиск максимального элемента
		return max_elem_main(HEAD);
	}

	BinaryTreeNode* search(int _val) const {
		BinaryTreeNode* result = search_main(HEAD, _val);
		return result;
	}


private:
	void destruct(BinaryTreeNode* bin_tree) {
		if(bin_tree != NULL) {
			destruct(bin_tree->left);
			destruct(bin_tree->right);
			delete bin_tree;
		}
	}
	void insert_main(BinaryTreeNode** bin_tree, const int& _val) { //  Основная работа вставки
		if(*bin_tree == 0) { //  Если пустой узел, то создаем
			*bin_tree = new BinaryTreeNode(_val);
		} else { 
			if((*bin_tree)->value > _val) {  //  Если значение меньше, то в левое поддерево
				insert_main((&(*bin_tree)->left), _val);
			} else {
				if((*bin_tree)->value < _val) {  //  Если значение больше, то в правое поддерево
					insert_main((&(*bin_tree)->right), _val);
				}
			}
		}
	}

	void remove_main(BinaryTreeNode** bin_tree, const int& _val) {  //  Основная работа удаления
		if((*bin_tree)->value == _val) { //  Нашли нужный узел
			BinaryTreeNode* delete_node = *bin_tree;

			if(((*bin_tree)->left == NULL) && ((*bin_tree)->right == NULL)) { //  Если лист
				*bin_tree = NULL;
				delete delete_node;
			} else {
				if((*bin_tree)->left == NULL) {  // Нет левого поддерева
					*bin_tree = (*bin_tree)->right;
					delete delete_node;
				} else {
					if((*bin_tree)->right == NULL) {  //  Нет правого поддерева
					*bin_tree = (*bin_tree)->left;
					delete delete_node;						
					} else {  //  Если обычный узел
						BinaryTreeNode* p = *bin_tree;
						BinaryTreeNode* i = (*bin_tree)->left;

						while(i->left != NULL) {
                		p = i;
                        i = i->right;
                    	}
 
	                    *bin_tree = i;
	                    p->right = i->left;
	                    i->right = delete_node->right;
	                    i->left = p;
	 
	                    delete delete_node;
					}
				}
			}
		} else {  //  Если еще не дошли до узла
			if((*bin_tree)->value > _val) {
				remove_main(&((*bin_tree)->left), _val);
			} else {
				remove_main(&((*bin_tree)->right), _val);
			}
		}
	}

	int depth_main(BinaryTreeNode* bin_tree) const {  //  Основаная работа по вычислению глубины дерева
		if((bin_tree->left == NULL) && (bin_tree->right == NULL)) {
			return 1;
		} else {
			if(bin_tree->left == NULL) {  // Нет левого поддерева
				return (1 + depth_main(bin_tree->right));
			} else {
				if(bin_tree->right == NULL) {  //  Нет правого поддерева
					return (1 + depth_main(bin_tree->left));
				} else {  // Иначе просто максимальную из глубин
					return (1 + std::max(depth_main(bin_tree->left), depth_main(bin_tree->right)));
				}
			}
		}
	} 

	void crawl_main(BinaryTreeNode* bin_tree) const {  //  Основной обход дерева
		if(bin_tree != NULL) {
			std::cout<<bin_tree->value<<"  ";
			crawl_main(bin_tree->left);  //  Сначала по левому поддереву
			crawl_main(bin_tree->right);  //  Потом по правому
		}
	}

	void print_tree_main(BinaryTreeNode* bin_tree, unsigned int _spaces) const {  //  Основная печать дерева
		while(bin_tree != NULL) {
			print_tree_main(bin_tree->right, _spaces + 5);

			for(int i = 1; i < _spaces; i++)
				std::cout<<" ";

			std::cout<<bin_tree->value<<std::endl;

			bin_tree = bin_tree->left;

			_spaces += 5;
		}
	}

	int min_elem_main(BinaryTreeNode* bin_tree) const {  //  Основной поиск минимального элемента
		int minimal;
		if(bin_tree->left == NULL) {
			minimal =  bin_tree->value;
		} else {
			if(bin_tree->left != NULL) {
				minimal = min_elem_main(bin_tree->left);
			} 
		}

		return minimal;
	}

	int max_elem_main(BinaryTreeNode* bin_tree) const {  //  Основной поиск максимального элемента
		int maximal;
		if(bin_tree->right == NULL) {
			maximal = bin_tree->value;
		} else {
			if(bin_tree->right != NULL) {
				maximal = max_elem_main(bin_tree->right);
			}
		}

		return maximal;
	}

	BinaryTreeNode* search_main(BinaryTreeNode* bin_tree, int _val) const{ //  Поиск
	 	BinaryTreeNode* res;
		if((bin_tree)->value == _val) { //  Если пустой узел, то создаем
			res = bin_tree;
		} else { 
			if((bin_tree)->value > _val) {  //  Если значение меньше, то в левое поддерево
				res = search_main(((bin_tree)->left), _val);
			} else {
				if((bin_tree)->value < _val) {  //  Если значение больше, то в правое поддерево
					res = search_main(((bin_tree)->right), _val);
				}
			}
		}
		return res;
	}

};	