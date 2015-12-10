#ifndef INTBINARYTREE_H
#define INTBINARYTREE_H
#include <iostream>

class IntBinaryTree
{
private:
	struct TreeNode
	{
		int value;
		TreeNode *left;
		TreeNode *right;
	};
	TreeNode *root;

	void insert(TreeNode *&, TreeNode *&);

	void deleteNode(int, TreeNode *&);
	void makeDeletion(TreeNode *&)const;
	void displayInOrder(TreeNode *) const;			// display
	void displayPreOrder(TreeNode *) const;			// display
	void displayPostOrder(TreeNode *) const;		// display
	TreeNode *trim(TreeNode *&,int ,int ) const;

public:
	IntBinaryTree()
	{
		root = NULL;
	}
	void destroySubTree (TreeNode *)const;
	~IntBinaryTree()
	{
		destroySubTree(root);
	}

	//Binary Tree Operations
	void insertNode(int);
	bool searchNode(int);
	void remove(int);
	void displayInOrder() const
	{
		displayInOrder(root);
	}

	void displayPreOrder() const
	{
		displayPreOrder(root);
	}

	void displayPostOrder() const
	{
		displayPostOrder(root);
	}
	void trim(int,int);


};

#endif
