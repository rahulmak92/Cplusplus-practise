#include "CircularQueue.h"
void CircularQueue::enqueue(int data)
{
	Node *newNode=new Node();
	newNode->data=data;
	if(front)
	{
		rear->next=newNode;
		rear=newNode;
		rear->next=front;
	}
	else
	{
		front=newNode;
		rear=newNode;
		newNode->next=front;
	}
}
void CircularQueue::printQ()
{
	if(front!=rear)
	{
		Node *tempNode;
		tempNode=front;
		while(tempNode!=rear)
		{
			cout<<tempNode->data<<"-->"<<endl;
			tempNode=tempNode->next;
		}
		cout<<tempNode->data<<endl;
	}
}
void CircularQueue::insertAt(Node *tempNode,int index,int value)
{
	if(index==1)
	{
		Node *newNode = new Node();
		newNode->data=value;
		newNode->next=tempNode->next;
		tempNode->next=newNode;
	}
	else
	{
		index--;
		insertAt(tempNode->next,index,value);
	}
}
