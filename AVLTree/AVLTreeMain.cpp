#include "AVLTree.h"
#include<ctime>
#include<cmath>
//  Функция вывода элемента на уровне
//  Дефайны
//  Закинуть в значение поля структура, неровное значение
//  усредненное значение времени
// 	r-b tree
void TEST1() {
	std::cout<<"START TEST 1"<<std::endl;
	AVLTree at;
	for(int i = 0; i < 100000000; i++) {
		at.insert(i*pow(-1,i));
	}
	long int start = clock();
	at.remove(25000000);
	long int end = clock();
	std::cout<<end - start<<std::endl;
	//AVLTreeNode* p = at.search(5000000);


	//at.print_tree_horizontal();
	//std::cout<<"-------------------"<<std::endl;
		//long int start = clock();
	/*int p;
	long int start = time(NULL);
	//std::cout<<"i"<<std::endl;
	//std::cin>>p;
	int j = at.get_head();
	std::cout<<"))"<<j<<std::endl;
	at.remove(1500000);
		long int end = clock();
	long int end = time(NULL);
	std::cout<<end - start<<std::endl;
	//at.print_tree_horizontal();
	int i = at.get_head();
	std::cout<<"---"<<i<<std::endl;*/
	std::cout<<"END TEST 1"<<std::endl;
}
void TEST2() {
	std::cout<<"START TEST 2"<<std::endl;
	AVLTree at;
	at.print_tree_horizontal();
	at.insert(1);
/*	at.print_tree_horizontal();*/
	at.insert(2);
	at.insert(3);
	at.print_tree_horizontal();
	std::cout<<"-------------------"<<std::endl;
	at.remove(3);
	at.print_tree_horizontal();
	std::cout<<"END TEST 2"<<std::endl;
}
void TEST3() {
	std::cout<<"START TEST 3"<<std::endl;
	AVLTree at;
	for(int i = 0; i < 10000000; i++)
		at.insert(rand() % 400000);
/*	at.print_tree_horizontal();*/
	std::cout<<"END TEST 3"<<std::endl;
}

void TEST4() {
	std::cout<<"START TEST 4"<<std::endl;
	AVLTree at;
	for(int i = 0; i < 15; i++) {
		at.insert(i);
	}
	at.print_tree_horizontal();
	std::cout<<"-------------------------------"<<std::endl;
	AVLTreeNode* p = at.search(13);
	std::cout<<(*p).get_value()<<std::endl;
	std::cout<<"END TEST 4"<<std::endl;
}

int main() {

	TEST1();
	//TEST2();
	//TEST3();
	//TEST4();
	return 0;
}