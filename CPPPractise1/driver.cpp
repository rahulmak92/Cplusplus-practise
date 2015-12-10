#include<iostream>
#include "Linklist.h"
using namespace std;

int main()
{
	Linklist list1;
	list1.insertNode(1);
	list1.insertNode(1);
	list1.insertNode(1);
	list1.insertNode(1);
	list1.insertNode(1);
	list1.insertNode(1);
	list1.insertNode(1);
	list1.displayList();
	list1.countNodes();
	cout<<"After deletion : "<<endl;
//	list1.deleteNode(8,&list1.head);
	list1.RemoveDuplicates();
	list1.displayList();

	return 0;
}
