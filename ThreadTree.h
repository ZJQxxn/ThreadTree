//ThreadTree.h : Declaretion of inorder thread binary tree.
#ifndef THREADTREE_H
#define THREADTREE_H
#include "ThreadNode.h"

//class:'ThreadTree'
//See implementation in ThreadTree.cpp
class ThreadTree
{
private:
	ThreadNode* root;

	//modify by using next()
	//ThreadNode* next(ThreadNode* current);
	ThreadNode* _find(int data);
	ThreadNode* _inOrderSucc(ThreadNode* node);
	ThreadNode* _inOrderPresucc(ThreadNode* node);
public:
	ThreadTree(int rootData);
	void addInLeft(int parentData, int data);
	void addInRight(int parentData, int data);
	void inTraverse();
	void preTraverse();
	void levelTraverse();

	//It is impossible to implement postorder traverse in a inorder thread binary tree
	//as the traverse iterator will finally reach at the real root, but the real root
	//has no thread point at root.
	//void postTraverse();
};
#endif