#include "IntList.h"
#include <iostream>
using namespace std;
void IntList :: insert(int num)
{
	Node *nodePtr;
	Node *newNode;
	newNode=new Node;
	newNode->value=num;
	newNode->next=NULL;
	if(!head)
	{
		head=newNode;
	}
	else
	{
		nodePtr=head;
		while(nodePtr->next)
		{
			nodePtr=nodePtr->next;
		}
		nodePtr->next=newNode;
		newNode->next=NULL;
	}
	cursor=newNode;
}
void IntList :: advance()
{
	cursor=cursor->next;
}
bool IntList :: isEmpty()
{
	if(!head)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool IntList :: atEOL()
{
	if(head)
	{
		Node *nodePtr;
		nodePtr=head;
		while(nodePtr->next)
		{
			nodePtr=nodePtr->next;
		}
		if(nodePtr->next==cursor)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		if(cursor==NULL)
		{
			return true;
		}
	}
}

int IntList :: getCurrent()
{
	if(atEOL())
	{
		return 0;
	}
	else
	{
		return cursor->value;
	}
}
void IntList :: resetFront()
{
	if(head)
	{
		cursor=head;
	}
	else
	{
		cursor=NULL;
	}
}
void IntList :: resetLast()
{
	Node *nodePtr,*previousNode;
	nodePtr=head;
	previousNode=NULL;
	while(nodePtr)
	{
		previousNode=nodePtr;
		nodePtr=nodePtr->next;
	}
	if(previousNode)
	{
		cursor=previousNode;
	}
	else
	{
		cursor=nodePtr;
	}
}
void IntList :: remove()
{
	if(cursor==head)
	{
		cursor=cursor->next;
		delete head;
		head=cursor;
	}
	else if(cursor==NULL)
	{
		return;
	}
	else
	{
		Node *nodePtr,*previousNode;
		nodePtr=head;
		previousNode=NULL;
		while(nodePtr!=cursor)
		{
			previousNode=nodePtr;
			nodePtr=nodePtr->next;
		}
		cursor=cursor->next;
		previousNode->next=cursor;
		delete nodePtr;
	}
}

void IntList::destroy()
{
	resetFront();
	while(!isEmpty())
	{
		remove();
	}
}
void IntList::deleteNode(int val,Node **list)
{
	if(!isEmpty())
	{
		Node *temp;
		temp=list;
		Node *prev=NULL;
		while(temp!=NULL && temp->value!=val)
		{
			prev=temp;
			temp=temp->next;
		}
		if(prev)
		{
			prev->next=temp->next;
			delete temp;
		}
		else
		{

		}

	}
}
