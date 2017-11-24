//main.cpp : Main function to test thread binary tree.
#include "ThreadTree.h"
#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
	ThreadTree tree(1);
	tree.addInLeft(1, 2);
	tree.addInLeft(2, 3);
	tree.addInRight(2, 4);
	tree.addInRight(1, 5);
	tree.addInLeft(1, 6);
	//tree.addInRight(1, 7);

	cout << "Level order traverse :";
	tree.levelTraverse();
	cout << "Inorder traverse :";
	tree.inTraverse();
	cout << "Preorder traverse :";
	tree.preTraverse();

	system("pause");
	return 0;
}