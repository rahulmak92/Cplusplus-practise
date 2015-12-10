#include<iostream>
#ifndef DLINKEDLIST_H
#define DLINKEDLIST_H
class DLinkedList
{
private:
		struct Node
		{
			int data;
			Node *prev;
			Node *next;
		};
		Node *head;
		Node *tail;
public:
		DLinkedList()
		{
			head=NULL;
			tail=NULL;
		}
		void insertAfter(int);
		void insertBefore(int);
		int popLast();
		int popFirst();
		void printData();
};
#endif
