#include<iostream>
using namespace std;
#ifndef LINKLIST_H
#define LINKLIST_H
class Linklist
{
	private:
	struct Node
	{
		int value;
		Node *next;
	};
	Node* head;
	public:
			Linklist();
			void insertNode(int);
			void displayList();
			int countNodes();
			void deleteNode(int);
			int getLastNode();
			void display_descending();
};
#endif
