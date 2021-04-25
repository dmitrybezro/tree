//  Узел Бинарного дерева
//  Где немного почитать: https://habr.com/ru/post/65617/
#pragma once

class BinaryTree;

class BinaryTreeNode {
	friend class BinaryTree;
private:
	int value = 0;
	BinaryTreeNode* left;
	BinaryTreeNode* right;
public:
	BinaryTreeNode(): left(NULL), right(NULL){}
	BinaryTreeNode(int _value): value(_value), left(NULL), right(NULL) {}
	BinaryTreeNode(const BinaryTreeNode& bt) {
		value = bt.value;
		left = bt.left;
		right = bt.right;
	}
	int GetValue() const{
		return value;
	}
};
