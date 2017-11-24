//ThreadTree.cpp : Implementation of class:'ThreadTree'
#include "ThreadTree.h"
#include <queue>
#include <iostream>
using namespace std;

//Constructor
ThreadTree::ThreadTree(int rootData)
{
	root = new ThreadNode(); 
	ThreadNode* realRoot = new ThreadNode(rootData);
	realRoot->leftChild = root;
	realRoot->rightChild = root;
	root->leftThread = false;
	root->leftChild = realRoot;
	root->rightThread = false;
	root->rightChild = root;
}


//private operations
/*
	Find the node given its data.
*/
ThreadNode* ThreadTree::_find(int data)
{
	queue<ThreadNode*> nodes;
	ThreadNode* current = root->leftChild;
	//while current is not a leaf node
	while (current->data!=data)
	{
		/*
		if (current->data == data)
		{
			return current;
		}
		*/
		//add child nodes of current in queue
		if (!current->leftThread)
		{
			nodes.push(current->leftChild);
		}
		if (!current->rightThread)
		{
			nodes.push(current->rightChild);
		}

		if (nodes.empty())
		{
			return nullptr;
		}
		current = nodes.front();
		nodes.pop();
	}
	return current;
}

/*
	Get inorder successor of 'node'.
*/
ThreadNode* ThreadTree::_inOrderSucc(ThreadNode* node)
{
	ThreadNode* current = root->leftChild;
	if (current->leftChild != node)
	{
		//find the leftmost leaf node
		while (!current->leftThread)
		{
			current = current->leftChild;
		}
	}
	//inorder traverse
	while (current->leftChild != node && current->rightChild != root)
	{
		current = current->rightChild;
	}
	return current;
}

/*
	Find the presuccessor of 'node'.
*/
ThreadNode* ThreadTree::_inOrderPresucc(ThreadNode* node)
{
	ThreadNode* current = root->leftChild;
	if(current->rightChild != node)
	{	
		//find the leftmost leaf node
		while (!current->leftThread)
		{
			current = current->leftChild;
		}
	}
	//inorder traverse
	while (current->rightChild != node && current->rightChild != root)
	{
		current = current->rightChild;
	}
	return current;
}

//public operations
/*
	Given 'data' and 'parentData' ,add the new data as 
	right child of the existing data depending on inorder
	traverse. 
*/
void ThreadTree::addInRight(int parentData, int data)
{
	ThreadNode* parent = _find(parentData);
	if (parent != nullptr)
	{
		ThreadNode* newNode=new ThreadNode(data);
		newNode->rightChild = parent->rightChild;
		newNode->rightThread = parent->rightThread;
		newNode->leftChild = parent;
		newNode->leftThread = true;
		parent->rightChild = newNode;
		parent->rightThread = false;
		if (!newNode->rightThread)
		{
			//set 'newNode' as presuccessor of leftchild of previous 'parent'
			ThreadNode* preNode = _inOrderSucc(newNode);
			preNode->leftChild = newNode;
		}
	}
}

/*
	Given 'data' and 'parentData' ,add the new data as
	left child of the existing data depending on inorder
	traverse.
*/
void ThreadTree::addInLeft(int parentData, int data)
{
	ThreadNode* parent = _find(parentData);
	if (parent != nullptr)
	{
		//add newNode as left child of parent
		ThreadNode* newNode = new ThreadNode(data);
		newNode->leftChild = parent->leftChild;
		newNode->leftThread = parent->leftThread;
		parent->leftThread = false;
		newNode->rightThread = true;
		newNode->rightChild = parent;
		parent->leftChild = newNode;
		//if parent has previous leftchild 
		if (!newNode->leftThread)
		{
			//find inorder successor of 'parent' node
			ThreadNode* preNode = _inOrderPresucc(parent);
			preNode->rightChild = newNode;
		}
	}
}

/*
	Traverse tree in inorder.
*/
void ThreadTree::inTraverse()
{
	ThreadNode* current = root->leftChild;
	//find the leftmost leaf node
	while (!current->leftThread)
	{
		current = current->leftChild;
	}

	//loop until reach at root node
	while (current->rightChild != current)
	{
		//start to traverse
		cout << current->data << "  ";
		current = current->rightChild;
	}
	cout << endl;
}

/*
	Preorder traverse a inorder thread binary tree.
*/
void ThreadTree::preTraverse()
{
	ThreadNode* current = root->leftChild;
	//ioop until reach at root
	while (current->rightChild != current)
	{
		cout << current->data << "  ";
		//has left child
		if (!current->leftThread)
		{
			current = current->leftChild;
		}
		else
		{
			//find the next right child
			while (current->rightThread)
			{
				current = current->rightChild;
			}
			current = current->rightChild;
		}
	}
	cout << endl;
}


/*
	Traverse tree in level order.
*/
void ThreadTree::levelTraverse()
{
	queue<ThreadNode*> nodes;
	ThreadNode* current = root->leftChild;
	while (current)
	{
		cout << current->data << "  ";
		if (!current->leftThread)
		{
			nodes.push(current->leftChild);
		}
		if (!current->rightThread)
		{
			nodes.push(current->rightChild);
		}
		if (nodes.empty())
		{
			cout << endl;
			return;
		}
		current = nodes.front();
		nodes.pop();
		//cout << current->data << "  ";
	}
}