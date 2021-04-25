#include "CartesianTree.h"
#include<ctime>
#include<cmath>
void TEST1() {  //  Вставка-удаление-глубина
	std::cout<<"START TEST 1"<<std::endl;
	CartesianTree ct;
	ct.print_tree_vertical();
	std::cout<<"-----------------------"<<std::endl;
	ct.insert(3);
	ct.insert(4);
	ct.print_tree_vertical();
	std::cout<<"-----------------------"<<std::endl;
	ct.insert(1);
	ct.print_tree_vertical();
	std::cout<<"-----------------------"<<std::endl;
	ct.insert(2);
	ct.insert(5);
	ct.print_tree_vertical();
	std::cout<<"-----------------------"<<std::endl;

	ct.remove(4);
	ct.print_tree_vertical();
			CartesianTreeNode* p = ct.search(5);
	std::cout<<"*** "<<(*p).GetValue()<<std::endl;
	//std::cout<<"Depth = "<<ct.depth()<<std::endl;
	std::cout<<"END TEST 1"<<std::endl;
}

void TEST4() {
	std::cout<<"START TEST 4"<<std::endl;
	CartesianTree bt;
	for(int i = 0; i < 10000000; i++) {
		bt.insert(rand() % 400000);
	}
		std::cout<<"END TEST 4"<<std::endl;
}
void TEST2() {
	std::cout<<"START TEST 2"<<std::endl;
	CartesianTree bt;
	for(int i = 0; i < 10000000; i++) {
		bt.insert(i*pow(-1,i));
	}
	bt.remove(5000000);
		std::cout<<"END TEST 2"<<std::endl;
}
int main() {

	TEST2();
	//TEST4();
	return 0;
}