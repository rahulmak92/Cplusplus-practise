#ifndef STACK_H
#define STACK_H
#include<iostream>
using namespace std;
class Stack
{
	private:
			int *stackArray;
			int stackCapacity;
			int top;
	public:
			Stack(int);//
			void push(int);//
			void pop_last();
			int topElement();//
			int size();//
			bool isEmpty();//
			bool isFull();//
			void display();//
};
#endif
