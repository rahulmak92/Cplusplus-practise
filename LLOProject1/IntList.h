#ifndef INTLIST_H
#define INTLIST_H
#include <iostream>

class IntList
{
private:
	struct Node
	{
		int value;
		struct Node *next;
		struct Node *previous;
	};
	Node *head;
	Node *last;
	//int count=0;
public:
	IntList()
	{
		head=NULL;
		last=NULL;
	}
	~IntList();
	void appendNum(int);
	void insertNum(int);
	void deleteNum(int);
	void display() ;
	void destroy();
	bool isEmpty();
	bool searchValue(int);
};
#endif
