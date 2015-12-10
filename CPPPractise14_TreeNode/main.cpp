#include "BinaryTree.h"
#include<iostream>
using namespace std;
int main()
{
	BinaryTree tree;
	cout<<"Inserting Node :";
	tree.insertNode(5);
	tree.insertNode(8);
	tree.insertNode(3);
	tree.insertNode(12);
	tree.insertNode(9);
	cout<<"In Order :"<<"\n";
	tree.displayInOrder();
	cout<<endl;
	cout<<"Post Order:"<<"\n";
	tree.displayPostOrder();
	cout<<endl;
	cout<<"Pre Order:"<<"\n";
	tree.displayPreOrder();

	cout<<"Min = "<<tree.findMin();
	return 0;
}
