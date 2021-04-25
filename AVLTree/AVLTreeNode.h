//  Узел АВЛ дерева
//  Красно-черные
//  Память
//  значение - указатель 
//  Таблички
#pragma once

class AVLTree;

class AVLTreeNode {
	friend class AVLTree;
private:

	int value;

	AVLTreeNode* left;
	AVLTreeNode* right;

	//  Высота поддерева с корнем в этом узле
	unsigned char height;

public:
	AVLTreeNode(int _val) : value(_val), height(1), left(nullptr), right(nullptr) {}
	int get_value() const {
		return value;
	}

};