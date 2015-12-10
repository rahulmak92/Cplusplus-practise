#include "IntQueue.h"
#include <iostream>
using namespace std;
IntQueue::IntQueue(int size)
{
	queueSize=size;
	queueArray= new int[queueSize];
	front=rear=-1;
	numOfItems=0;
}
IntQueue::IntQueue(const IntQueue &second)
{
	queueSize=second.queueSize;
	queueArray=new int[queueSize];
	front=second.front;
	rear=second.rear;
	numOfItems=second.numOfItems;
	for(int i=0;i<=queueSize;i++)
	{
		queueArray[i]=second.queueArray[i];
	}
}
void IntQueue::enqueue(int val)
{
	if(isFull())
	{
		cout<<"the queue is full.\n";
	}
	else
	{
		rear=(rear+1)%queueSize;
		queueArray[rear]=val;
		numOfItems++;
	}
}
void IntQueue::dequeue(int &val)
{
	if(isEmpty())
	{
		cout<<"Is Empty";
	}
	else
	{
		front=(front+1)%queueSize;
		val=queueArray[front];
		numOfItems--;
	}
}
bool IntQueue::isEmpty() const
{
	bool status;
	if(numOfItems>0)
	{
		status=true;
	}
	else
	{
		status=false;
	}
	return status;
}
bool IntQueue::isFull()const
{
	if(numOfItems<queueSize)
	{
		return false;
	}
	else
	{
		return true;
	}
}
IntQueue::~IntQueue()
{
	delete [] queueArray;
}
void IntQueue::clear()
{
	front=queueSize-1;
	rear=queueSize-1;
	numOfItems=0;
}
