#include "DynIntQueue.h"
#include <iostream>
using namespace std;
DynIntQueue::DynIntQueue()
{
	front=NULL;
	rear=NULL;
	numItems=0;
}
DynIntQueue::~DynIntQueue()
{
	clear();
}
void DynIntQueue::clear()
{
	int value;
	while(!isEmpty())
	{
		dequeue(value);
	}
}
bool DynIntQueue::isEmpty()const
{
	if(numItems>0)
	{
		return false;
	}
	else
	{
		return true;
	}
}
void DynIntQueue::enqueue(int val)
{
	QueueNode *newNode;
	newNode =  new QueueNode;
	newNode->value=val;
	newNode->next=NULL;
	if(isEmpty())
	{
		front=newNode;
		rear=newNode;
	}
	else
	{
		rear->next=newNode;
		rear=newNode;
	}
	numItems++;
}
void DynIntQueue::dequeue(int &val)
{
	if(isEmpty())
	{
		cout<<"Empty queue!";
	}
	else
	{
		QueueNode *temp;
		val=front->value;
		temp=front;
		front=front->next;
		delete temp;
		numItems--;
	}
}
