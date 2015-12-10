#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
class LinkedList
{
	private:
			struct Node
			{
				int data;
				Node *next;
			};
			Node *head;
			void setData(int);
			int getData();
	public:
			LinkedList();
			void insertNode(int);
			int getNodeVal(Node);

};
#endif
