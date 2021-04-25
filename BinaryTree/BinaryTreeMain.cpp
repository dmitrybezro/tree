
#include"BinaryTree.h"
#include<ctime>
#include<cmath>
void TEST1() {  //  Вставка-удаление-глубина
	std::cout<<"START TEST 1"<<std::endl;
	BinaryTree bt;
	bt.print_tree();
	bt.insert(3);
	bt.insert(4);
	bt.print_tree();
	bt.insert(1);
	bt.print_tree();
	bt.insert(2);
	bt.insert(5);
	bt.print_tree();
	bt.remove(4);
	bt.print_tree();
	BinaryTreeNode* p = bt.search(5);
	std::cout<<"*** "<<(*p).GetValue()<<std::endl;
	std::cout<<"Depth = "<<bt.depth()<<std::endl;
	std::cout<<"END TEST 1"<<std::endl;
}

void TEST2() {  //  Вырождение дерева
	std::cout<<"START TEST 2"<<std::endl;
	BinaryTree bt;
	for(int i = 0; i < 30000; i++) {
		bt.insert(i*pow(-1, i));
	}
/*	int start = clock();
	BinaryTreeNode* p = bt.search(29999);
	int end = clock();
	std::cout<<"insert 10000000 elem = "<<end - start<<std::endl;
	bt.print_tree();*/
	bt.remove(15000);
	std::cout<<"END TEST 2"<<std::endl;
}

void TEST3() {  //  Рандомные значения + обход
	std::cout<<"START TEST 3"<<std::endl;
	BinaryTree bt;
	for(int i = 0; i < 15; i++) {
		bt.insert(rand() % 30);
	}
	bt.print_tree();
	bt.crawl();
	
	std::cout<<"END TEST 3"<<std::endl;
}

void TEST4() {  //  Минимальное и максимальное значения
	std::cout<<"START TEST 4"<<std::endl;
	BinaryTree bt;
	for(int i = 0; i < 200000; i++) {
		bt.insert(rand() % 400000);
	}
	bt.min_elem();
	
	//int max = bt.max_elem();
	bt.print_tree();
	std::cout<<"min = "<<bt.min_elem()<<std::endl;
	std::cout<<"max = "<<bt.max_elem()<<std::endl;
	
	std::cout<<"END TEST 4"<<std::endl;
}

void TEST5() {  //  Время создания дерева
	//std::cout<<"START TEST 5"<<std::endl;
	BinaryTree bt;
	int size = 10000000;
	int start = clock();
	for(int i = 0; i < size; i++) {
		bt.insert(rand() % 400000);
	}
		//bt.print_tree();
/*	int end = clock();
	std::cout<<"insert 10000000 elem = "<<end - start<<std::endl;*/
	
	//std::cout<<"END TEST 5"<<std::endl;
}


int main() {
	   	// srand(time(0));

	//TEST1();
	TEST2();
	//TEST3();
	//TEST4();
	//TEST5();

	return 0;
}
