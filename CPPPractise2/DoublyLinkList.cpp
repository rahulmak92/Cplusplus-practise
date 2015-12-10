#include "DoublyLinkList.h"
DoublyLinkList::DoublyLinkList()
{
	head=NULL;
}
void DoublyLinkList::insertNode(int val)
{
	DNode *newNode;
	DNode *nodePtr,*previousNode;
	newNode= new DNode;
	newNode->data=val;
	newNode->next=NULL;
	newNode->previous=NULL;
	if(!head)
	{
		head=newNode;
	}
	else
	{
		nodePtr=head;
		previousNode=NULL;
		while(nodePtr!=NULL && nodePtr->data<val)
		{
			previousNode=nodePtr;
			nodePtr=nodePtr->next;
		}
		if(previousNode==NULL)
		{
			head=newNode;
			head->next=nodePtr;
		}
		else
		{
			previousNode->next=newNode;
			newNode->previous=previousNode;
			newNode->next=nodePtr;
		}
	}
}
void DoublyLinkList::displayList()
{
	DNode *nodePtr;
	nodePtr=head;
	int count=0;
	cout<<"Head : "<<head->data<<endl;
	while(nodePtr!=NULL)
	{
		if(nodePtr==head)
		{
			cout<<"NULL";
		}
		cout<<"<--"<<nodePtr->data<<"-->";
		if(nodePtr->next==NULL)
		{
			cout<<"NULL";
		}
		nodePtr=nodePtr->next;
		count++;
	}
}
void DoublyLinkList::deleteNode(int val)
{
	DNode *nodePtr;
	DNode *previousNode=NULL;
	nodePtr=head;
	while(nodePtr!=NULL && nodePtr->data!=val)
	{
		previousNode=nodePtr;
		nodePtr=nodePtr->next;
	}
	if(previousNode==NULL)
	{
		head=nodePtr->next;
		head->previous=NULL;
	}
	else
	{
		previousNode->next=nodePtr->next;
		nodePtr->next->previous=previousNode;
		delete nodePtr;
	}
}
