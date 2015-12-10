#include "DoublyLinkList.h"
#include<iostream>
using namespace std;
int main()
{
	DoublyLinkList list;
	list.insertNode(23);
	list.insertNode(67);
	list.insertNode(2);
	list.insertNode(11);
	list.insertNode(89);
	list.insertNode(298);
	list.insertNode(1);
	list.insertNode(65);
	list.displayList();
	cout<<endl<<"deleting :"<<endl;
	list.deleteNode(23);
	list.displayList();
	cout<<endl<<"deleting 1st"<<endl;
	list.deleteNode(1);
	list.displayList();
	return 0;
}
