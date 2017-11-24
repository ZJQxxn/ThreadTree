//ThreadNode.h : Declaretion of nodes of thread binary tree.
#ifndef THREADNODE_H
#define THREADNODE_H

class ThreadTree;

//class:'ThreadNode'
class ThreadNode
{
	friend class ThreadTree;
private:
	int data;
	ThreadNode* leftChild;
	ThreadNode* rightChild;
	bool leftThread;
	bool rightThread;
public:
	ThreadNode(int data = -1)
		:data(data)
		, leftChild(nullptr)
		, rightChild(nullptr)
		, leftThread(true)
		, rightThread(true)
	{
	}
};
#endif