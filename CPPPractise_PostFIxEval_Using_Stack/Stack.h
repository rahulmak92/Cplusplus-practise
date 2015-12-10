#include "LinkList.h"
#ifndef STACK_H
#define STACK_H

class Stack
{
	private:
			Linklist list;
	public:
			Stack();
			void pop();
			void push(int);
			bool isFull();
			bool isEmpty();
			void display();
			int topElement();
			int size();
};
#endif
