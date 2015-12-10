#include "IntList.h"
#include <iostream>
using namespace std;
#ifndef INTSTACK_H
#define INTSTACK_H
//IntStack header file
//Lab 9
//Fall 2014

class IntStack
{
	private:
			IntList stack;
	public:
			IntStack();
			void push(int);
			int pop();
			bool isEmpty();
			bool isFull();
};

#endif
