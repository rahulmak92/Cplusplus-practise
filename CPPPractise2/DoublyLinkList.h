#ifndef DOUBLYLINKLIST_H
#define DOUBLYLINKLIST_H
#include<iostream>
using namespace std;
class DoublyLinkList
{
	private:
			struct DNode
			{
				int data;
				DNode *next;
				DNode *previous;
			};
			DNode *head;
	public:
			DoublyLinkList();
			void insertNode(int);
			void displayList();
			void countNodes();
			void deleteNode(int);
};
#endif
