#include "IntBinaryTree.h"
#include <iostream>

using namespace std;
//def trimBST(tree, minVal, maxVal):
//		if not tree:
//		return
//		tree.left=trimBST(tree.left, minVal, maxVal)
//		tree.right=trimBST(tree.right, minVal, maxVal)
//		if minVal<=tree.val<=maxVal:
//		return tree
//		if tree.val<minVal:
//		return tree.right
//		if tree.val>maxVal:
//		return tree.left
TreeNode IntBinaryTree::trim(TreeNode *&nodePtr,int max,int min) const
{
	if(!nodePtr)
	{
		return NULL;
	}
	nodePtr->left=trim(nodePtr->left,max,min);
	nodePtr->right=trim(nodePtr->right,max,min);
	if(min<=nodePtr->value && nodePtr->value<=max)
	{
		return nodePtr;
	}

}

void IntBinaryTree::trim(int max,int min)
{
	trim(root,max,min);
}
// ***************************Insertion Functions*****************************
void IntBinaryTree :: insertNode (int num)
{
	TreeNode *newNode;

	// Create a new node and store num in it
	newNode = new TreeNode;
	newNode->value = num;
	newNode->left = newNode->right = NULL;

	//Insert the node
	insert(root, newNode);
}

void IntBinaryTree :: insert(TreeNode *&nodePtr, TreeNode *&newNode)
{
	if(nodePtr == NULL)
		nodePtr = newNode;
	else if(newNode->value < nodePtr->value)
		insert(nodePtr->left, newNode);
	else
		insert(nodePtr->right, newNode);
}



// *************************Search Node*******************************
bool IntBinaryTree :: searchNode(int num)
{
	TreeNode *nodePtr = root;

	while(nodePtr)
	{
		if(nodePtr->value == num)
			return true;
		else if(num < nodePtr->value)
			nodePtr = nodePtr->left;
		else
			nodePtr = nodePtr->right;
	}
	return false;
}

// **************************Deletion************************************
void IntBinaryTree :: remove(int num)
{
	deleteNode(num, root);
}

void IntBinaryTree :: deleteNode(int num, TreeNode *& nodePtr)
{
	if(nodePtr == NULL)
		return;
	else
	{	if(num < nodePtr->value)
		deleteNode(num, nodePtr->left);
		else if(num > nodePtr->value)
		deleteNode(num, nodePtr->right);
		else
		makeDeletion(nodePtr);
	}
}

void IntBinaryTree :: makeDeletion (TreeNode *&nodePtr)
{
	// Define a temporary pointer to use in reacttaching
	//the left subtree
//	cout<<"Came here"<<nodePtr->value;

	TreeNode *tempNodePtr;
	tempNodePtr=NULL;
	if(nodePtr == NULL)
		cout << "Cannot delete empty node. \n";
	else if (nodePtr->right == NULL)
	{
		tempNodePtr = nodePtr;
		nodePtr = nodePtr->left;
		delete tempNodePtr;
	}
	else if (nodePtr->left == NULL)
	{
		tempNodePtr = nodePtr;
		nodePtr = nodePtr->right;
		delete tempNodePtr;
	}
	// If the node has two children
	else
	{
		// Move one node to the right.
		tempNodePtr = nodePtr->right;
		// Go to the end left node.
		while ( tempNodePtr->left)
			tempNodePtr = tempNodePtr->left;
		// Reattach the left subtree
		tempNodePtr->left = tempNodePtr->right;
		tempNodePtr = nodePtr;
		// Reattach the right subtree
		tempNodePtr = tempNodePtr->right;
		delete tempNodePtr;
	}
}

void IntBinaryTree :: destroySubTree(TreeNode *nodePtr)
{
	if (nodePtr)
	{
		if (nodePtr->left)
			destroySubTree(nodePtr->left);
		if(nodePtr->right)
			destroySubTree(nodePtr->right);
		delete nodePtr;
	}
}
// ***************************** Display Functions ******************************
void IntBinaryTree :: displayInOrder(TreeNode *nodePtr) const
{
	if(nodePtr)
	{
		displayInOrder(nodePtr->left);
		cout << nodePtr->value << endl;
		displayInOrder(nodePtr->right);
	}
}

void IntBinaryTree :: displayPreOrder(TreeNode *nodePtr) const
{
	if(nodePtr)
	{
		cout << nodePtr->value << endl;
		displayPreOrder(nodePtr->left);
		displayPreOrder(nodePtr->right);
	}

}

void IntBinaryTree :: displayPostOrder(TreeNode *nodePtr) const
{
	if(nodePtr)
	{
		displayPostOrder(nodePtr->left);
		displayPostOrder(nodePtr->right);
		cout << nodePtr->value << endl;
	}
}
