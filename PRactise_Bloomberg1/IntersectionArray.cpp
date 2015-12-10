#include "IntersectionArray.h"
using namespace std;
IntersectionArray::IntersectionArray(int size)
{
	stackCapacity=size;
	top=-1;
	stackArray = new int[size];
}
void IntersectionArray::push(int val)
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
void IntersectionArray::display()
{
	int index;
	cout<<"Stack:"<<"\n";
	for(index=size()-1;index>=0;index--)
	{
		cout<<"\t"<<stackArray[index]<<"\n";
	}
}
int IntersectionArray::size()
{
	return top+1;
}
bool IntersectionArray::isFull()
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
bool IntersectionArray::isEmpty()
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
int IntersectionArray::topElement()
{
	return stackArray[top];
}
void IntersectionArray::pop_last()
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
