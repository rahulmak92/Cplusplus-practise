#include "BinarySearchTree.h"
using namespace std;
int main()
{
	BinarySearchTree tree;
	tree.insertNode(2);
	tree.insertNode(3);
	tree.insertNode(4);
	tree.insertNode(6);
	tree.insertNode(7);
	tree.insertNode(9);
	tree.insertNode(13);
	tree.insertNode(15);
	tree.insertNode(17);
	tree.insertNode(18);
	tree.insertNode(20);
	tree.displayInOrder();
	return 0;
}
