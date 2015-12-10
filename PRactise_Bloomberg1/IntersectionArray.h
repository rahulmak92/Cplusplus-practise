#ifndef INTERSECTIONARRAY_H
#define INTERSECTIONARRAY_H
#include <iostream>
class IntersectionArray
{
	private:
			int *stackArray;
			int stackCapacity;
			int top;
	public:
			IntersectionArray(int);//
			void push(int);//
			void pop_last();
			int topElement();//
			int size();//
			bool isEmpty();//
			bool isFull();//
			void display();//
};
#endif
