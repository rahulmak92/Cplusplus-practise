#ifndef INTLIST_H
#define INTLIST_H
#include <iostream>

using namespace std;

class IntList
{
	private:
		struct Node
		{
			double value;
			Node *next;
		};
		Node *head;
		Node *cursor;

	public:
		IntList()
		{
			head = NULL;
			cursor = NULL;
		}
		~IntList()
		{
			destroy();
		}
		void deleteNode(int ,Node **);
		void insert(int);
		void advance();
		bool isEmpty();
		bool atEOL();
		int getCurrent();
		void resetFront();
		void resetLast();
		void remove();
		void destroy();
};
#endif
