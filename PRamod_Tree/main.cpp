#include <iostream>
#include "IntBinaryTree.h"

using namespace std;

int main()
{
	IntBinaryTree tree;

	cout << "Inserting nodes.   ";
	tree.insertNode(5);
	tree.insertNode(8);
	tree.insertNode(3);
	tree.insertNode(12);
	tree.insertNode(9);
	cout << "Done. \n";

	// Display inorder
	cout << "Inorder traversal : \n";
	tree.displayInOrder();

	// Display preorder
	cout << "\nPreorder traversal : \n";
	tree.displayPreOrder();

	// Display postorder
	cout << "\nPostorder traversal : \n";
	tree.displayPostOrder();

	// Search for the value 3
	cout << endl << "Search Function ....  " << endl;
	if(tree.searchNode(3))
		cout << "3 is found in the tree. \n";
	else
		cout << "3 is not fount in the tree. \n";

	// Search for the value 100
	if(tree.searchNode(100))
		cout << "100 is found in the tree. \n";
	else
		cout << "100 is not found in the tree. \n";

	// Delete the Value 8.
	cout << endl << "Deleting 8 .... \n";
	tree.remove(8);

	// Display the values
	cout << "Now, here are the nodes:  \n";
	tree.displayInOrder();
	return 0;
}
