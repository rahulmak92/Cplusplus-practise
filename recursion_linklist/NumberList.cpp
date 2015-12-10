#include "NumberList.h"
int NumberList:: countNodes(ListNode *nodePtr) const
{
	if(nodePtr!=NULL)
		return 1+countNodes(nodePtr->next);
	else
		return 0;
}
void NumberList:: appendNode(double num)
{
	ListNode *nodePtr;
	ListNode *newNode;
	newNode=new ListNode;
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
	}
}
NumberList::~NumberList()
{
	ListNode *nodePtr;
	ListNode *nextNode;
	nodePtr=head;
	while(nodePtr!=NULL)
	{
		nextNode=nodePtr->next;
		delete nodePtr;
		nodePtr=nextNode;
	}
}
void NumberList::insertNode(double num)
{
	ListNode *newNode;
	ListNode *nodePtr;
	ListNode *previousNode;
	newNode=new ListNode;
	newNode->value=num;
	if(head==NULL)
	{
		head=newNode;
		newNode->next=NULL;
	}
	else
	{
		nodePtr=head;
		previousNode=NULL;
		while(nodePtr!=NULL && nodePtr->value<num)
		{
			previousNode=nodePtr;
			nodePtr=nodePtr->next;
		}
		if(previousNode==NULL)
		{
			head=newNode;
			newNode->next=nodePtr;
		}
		else
		{
			previousNode->next=newNode;
			newNode->next=nodePtr;
		}
	}
}
void NumberList::deleteNode(double num)
{
	ListNode *nodePtr;
	ListNode *previousNode;
	if(!head)
	{
		return;
	}
	else
	{
		nodePtr=head;
		while(nodePtr!=NULL && nodePtr->value!=num )
		{
			previousNode=nodePtr;
			nodePtr=nodePtr->next;
		}
		if(nodePtr)
		{
			previousNode->next=nodePtr->next;
			delete nodePtr;
		}
	}
}
void NumberList::displayList() const
{
	ListNode *nodePtr;
	nodePtr=head;
	if(!head)
	{
		cout<<"Empty List!\n";
	}
	else
	{
		while(nodePtr!=NULL)
		{
			cout<<nodePtr->value<<"---->";
			if(nodePtr->next==NULL)
				cout<<"NULL";
			nodePtr=nodePtr->next;
		}
	}
}
void NumberList::showReverse(ListNode *nodePtr) const
{
	if(nodePtr)
	{
		showReverse(nodePtr->next);
		cout<<nodePtr->value<<"---->";
	}
	else
	{
		cout<<"NULL---->";
	}
}
