#include "Stack.h"
Stack::Stack(int size)
{
	stackCapacity=size;
	top=-1;
	stackArray = new int[size];
}
void Stack::push(int val)
{
	if(!isFull())
	{
		top=top+1;
		stackArray[top]=val;
	}
	else
	{
		cout<<"Stack is full sorry!"<<endl;
	}
}
void Stack::display()
{
	int index;
	cout<<"Stack:"<<"\n";
	for(index=size()-1;index>=0;index--)
	{
		cout<<"\t"<<stackArray[index]<<"\n";
	}
}
int Stack::size()
{
	return top+1;
}
bool Stack::isFull()
{
	if(size()<stackCapacity)
	{
		return false;
	}
	else if(size()>=stackCapacity)
	{
		return true;
	}
	else
	{
		return true;
	}
}
bool Stack::isEmpty()
{
	if(top==-1)
	{
		return true;
	}
	else
	{
		return false;
	}
}
int Stack::topElement()
{
	return stackArray[top];
}
void Stack::pop_last()
{
	if(isEmpty())
	{
		cout<<"Stack is empty!!"<<endl;
	}
	else
	{
		top--;
	}

}
