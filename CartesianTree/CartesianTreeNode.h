//  Узел Декартового дерева

#pragma once

#include<random>		

//  Функция рандома
double DoubleRand(){ 
	double _max = 0;
	double _min = 1;
	return _min + double(rand()) / RAND_MAX * (_max - _min); 
}

class CartesianTree;

class CartesianTreeNode {
	friend class CartesianTree;
private:
	int value = 0;
	double prior;
	CartesianTreeNode* left;
	CartesianTreeNode* right;
public:
	CartesianTreeNode(): left(NULL), right(NULL){}
	CartesianTreeNode(int _value): value(_value), left(NULL), right(NULL) {
		prior = DoubleRand();
	}
	CartesianTreeNode(int _value, double _prior): value(_value), prior(_prior), left(NULL), right(NULL) {}
	CartesianTreeNode(const CartesianTreeNode& bt) {
		value = bt.value;
		prior = bt.prior;
		left = bt.left;
		right = bt.right;
	}
	int GetValue() const{
		return value;
	}
	double GetPrior() const{
		return prior;
	}

};

