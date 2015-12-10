#include "BinaryTree.h"
#include <iostream>
using namespace std;
BinaryTree::BinaryTree()
{
	root=NULL;
}
BinaryTree::~BinaryTree()
{
	destroySubTree(root);
}
void BinaryTree::insertNode(int num)
{
	TreeNode *newNode;
	newNode =  new TreeNode;
	newNode->value=num;
	newNode->left=newNode->right=NULL;
	insert(root,newNode);
}
void BinaryTree::insert(TreeNode *&nodePtr,TreeNode *&newNode)
{
	if(nodePtr==NULL)
	{
		nodePtr=newNode;
	}
	else if(newNode->value<nodePtr->value)
	{
		insert(nodePtr->left,newNode);
	}
	else
	{
		insert(nodePtr->right,newNode);
	}
}
void BinaryTree::destroySubTree(TreeNode *nodePtr)
{
	if(nodePtr)
	{
		if(nodePtr->left)
		{
			destroySubTree(nodePtr->left);
		}
		if(nodePtr->right)
		{
			destroySubTree(nodePtr->right);
		}
		delete nodePtr;
	}
}
void BinaryTree::displayInOrder(TreeNode *nodePtr)const
{
	if(nodePtr)
	{
		displayInOrder(nodePtr->left);
		cout<<nodePtr->value<<"\t";
		displayInOrder(nodePtr->right);
	}
}
void BinaryTree::displayPreOrder(TreeNode *nodePtr)const
{
	if(nodePtr)
	{
		cout<<nodePtr->value<<"\t";
		displayPreOrder(nodePtr->left);
		displayPreOrder(nodePtr->right);
	}
}
void BinaryTree::displayPostOrder(TreeNode *nodePtr)const
{
	if(nodePtr)
	{
		displayPostOrder(nodePtr->left);
		displayPostOrder(nodePtr->right);
		cout<<nodePtr->value<<"\t";
	}
}
bool BinaryTree::searchNode(int val)
{
	TreeNode *nodePtr;
	nodePtr=root;
	while(nodePtr)
	{
		if(nodePtr->value==val)
		{
			return true;
		}
		else if(nodePtr->value>val)
		{
			nodePtr=nodePtr->left;
		}
		else
		{
			nodePtr=nodePtr->right;
		}
	}
	return false;
}
void BinaryTree::remove(int val)
{
	deleteNode(val,root);
}
void BinaryTree::deleteNode(int val,TreeNode *&nodePtr)
{
	if(val<nodePtr->value)
	{
		deleteNode(val,nodePtr->left);
	}
	else if(val>nodePtr->value)
	{
		deleteNode(val,nodePtr->right);
	}
	else
		makeDeletion(nodePtr);
}
void BinaryTree::makeDeletion(TreeNode *&nodePtr)
{
	TreeNode *tempNodePtr;
	if(nodePtr==NULL)
	{
		cout<<"Empty Node!";
	}
	else if(nodePtr->right==NULL)
	{
		tempNodePtr= nodePtr;
		nodePtr=nodePtr->left;
		delete tempNodePtr;
	}
	else if(nodePtr->left==NULL)
	{
		tempNodePtr=nodePtr;
		nodePtr=nodePtr->right;
		delete tempNodePtr;
	}
	else
	{
		tempNodePtr=nodePtr->right;
		while(tempNodePtr->left)
		{
			tempNodePtr=tempNodePtr->left;
		}
		tempNodePtr->left=nodePtr->left;
		tempNodePtr=nodePtr;
		nodePtr=nodePtr->right;
		delete tempNodePtr;
	}
}
int BinaryTree::findMin(TreeNode *nodePtr)
{
	int min=0;
	while(nodePtr->left)
	{
		nodePtr=nodePtr->left;
	}
	min=nodePtr->value;
	return min;
}
