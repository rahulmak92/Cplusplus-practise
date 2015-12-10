#include "BinarySearchTree.h"
void BinarySearchTree::insertNode(int num)
{
	TreeNode *newNode;
	newNode=new TreeNode;
	newNode->data=num;
	newNode->right=NULL;
	newNode->left=NULL;
	insert(root,newNode);
}
void BinarySearchTree::insert(TreeNode *&nodePtr,TreeNode *&newNode)
{
	if(nodePtr==NULL)
	{
		nodePtr=newNode;
	}
	else if(nodePtr->data>newNode->data)
	{
		insert(nodePtr->left,newNode);
	}
	else
	{
		insert(nodePtr->right,newNode);
	}
}
void BinarySearchTree::displayInOrder(TreeNode *nodePtr)const
{
    if(nodePtr)
    {
        displayInOrder(nodePtr->left);
        std::cout<<nodePtr->data<<std::endl;
        displayInOrder(nodePtr->right);
    }
}
