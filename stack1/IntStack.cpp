#include "IntStack.h"
#include<iostream>
using namespace std;
IntStack::IntStack(int size)
{
	stackArray=new int[size];
	stacksize=size;
	top=-1;
}
IntStack::IntStack(const IntStack &obj)
{
	if(obj.stacksize>0)
	{
		stackArray=new int[obj.stacksize];
	}
	else
	{
		stackArray=NULL;
	}
	stacksize=obj.stacksize;
	for(int count=0;count<stacksize;count++)
	{
		stackArray[count]=obj.stackArray[count];
	}
	top=obj.top;
}
IntStack::~IntStack()
{
	delete []stackArray;
}
void IntStack::push(int num)
{
	if(isFull())
	{
		cout<< "The stack is full.\n";
	}
	else
	{
		top++;
		stackArray[top]=num;
	}
}
void IntStack::pop(int &num)
{
	if(isEmpty())
	{
		cout<<"The stack have nothing :( .\n";
	}
	else
	{
		num=stackArray[top];
		top--;
	}
}
bool IntStack::isFull() const
{
	bool status;
	if(top==stacksize-1)
	{
		status = true;
	}
	else
		status=false;
	return status;
}
bool IntStack::isEmpty() const
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
