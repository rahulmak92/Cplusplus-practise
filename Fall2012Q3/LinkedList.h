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
	public:
			LinkedList()
			{
				head=NULL;
			}
			void addNode(int val);
			void deleteNode(int val);
			int deleteNode();
			void displayList();
			void findMode();
};
#endif
