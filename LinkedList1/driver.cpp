#include "NumberList.h"
#include<iostream>
using namespace std;
int main()
{
	NumberList list;
	list.appendNode(12);
	list.appendNode(3);
	list.appendNode(15);
	list.appendNode(6);
	/*
	list.insertNode(12);
	list.insertNode(3);
	list.insertNode(15);
	list.insertNode(6);
	list.insertNode(14);*/
//	cout<<"Initial values : \n";
	list.displayList();
	cout<<endl;
	cout<<"deleting the node in the middle.\n";
	list.deleteNode(3);
	cout<<"Left nodes. \n";
	list.displayList();
	cout<<endl;
	/*
	cout<<"Now deleting last node.\n";
	list.deleteNode(12.6);
	cout<<"Left nodes : \n";
	list.displayList();
	cout<<endl;
	cout<<"now deletinng the only reamaining node.\n";
	list.deleteNode(12.5);
	cout<<"here are the nodes left. \n";
	list.displayList();
*/	return 0;
}
