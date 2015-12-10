#ifndef STACK_H
#define STACK_H
#include<iostream>
using namespace std;
template <class T>
class Stack
{
	private:
			T *stackArray;
			int stackSize;
			int top;
	public:
			Stack(int);
			Stack(const Stack&);
			~Stack();
			void push(T);
			void pop(T&);
			bool isFull();
			bool isEmpty();
};
template <class T>
Stack<T>::Stack(int size)
{
	stackArray=new T[size];
	stackSize=size;
	top=-1;
}
template <class T>
Stack<T>::Stack(const Stack &obj)
{
	if(stackSize>0)
	{
		stackArray=new T[obj.stackSize];
	}
	else
	{
		stackArray=NULL;
	}
	stackSize=obj.stackSize;
	for(int count=0;count<stackSize;count++)
	{
		stackArray[count]=obj.stackArray[count];
	}
	top=obj.top;
}
template <class T>
Stack<T>::~Stack()
{
	if(stackSize>0)
	{
		delete [] stackArray;
	}
}
template <class T>
void Stack<T>::push(T item)
{
	if(isFull())
	{
		cout<<"Stack is full\n";
	}
	else
	{
		top++;
		stackArray[top]=item;
	}
}
template <class T>
void Stack<T>::pop(T &item)
{
	if(isEmpty())
	{
		cout<<"the stack is empty.\n";
	}
	else
	{
		item=stackArray[top];
		top--;
	}
}
template <class T>
bool Stack<T>::isFull()
{
	bool status;
	if(top==stackSize-1)
	{
		status=true;
	}
	else
	{
		status=false;
	}
	return status;
}
template <class T>
bool Stack<T>::isEmpty()
{
	bool status;
	if(top==-1)
	{
		status=true;
	}
	else
	{
		status=false;
	}
	return status;
}
#endif
