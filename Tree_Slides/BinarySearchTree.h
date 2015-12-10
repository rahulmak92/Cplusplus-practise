#include<iostream>
#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H
class BinarySearchTree
{
	private:
			struct TreeNode
			{
				int data;
				TreeNode *left;
				TreeNode *right;
			};
			TreeNode *root;
			void insert(TreeNode *&,TreeNode *&);
			void displayInOrder(TreeNode *) const;
	public:
			BinarySearchTree()
			{
				root=NULL;
			}
			void insertNode(int);
			void displayInOrder()const
			{
				displayInOrder(root);
			}
};
#endif
