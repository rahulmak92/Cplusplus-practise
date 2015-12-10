#ifndef STACK_H
#define STACK_H
#include <iostream>
using namespace std;
class Stack
{
	private:
			int *stackArray;
			int stackSize;
			int top;
	public:
			Stack(int);
			void push(int);
			int pop();
			bool isFull();
			bool isEmpty();
			void displayElements();
			string *displayInWords();
			string disp_single(int);
			string disp_ten(int);
			string disp_1_single(int);
			string disp_hundreds(int);
			string disp_thousands(int);
};
#endif
