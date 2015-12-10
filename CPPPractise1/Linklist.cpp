#include "Linklist.h"
Linklist::Linklist()
{
	head= NULL;
}
void Linklist::insertNode(int val)
{
	Node *newNode;
	Node *nodePtr,*previousNode;
	newNode=new Node;
	newNode->value=val;
	newNode->next=NULL;
	if(!head)
	{
		head=newNode;
	}
	else
	{
		nodePtr=head;
		previousNode=NULL;
		while(nodePtr!=NULL && nodePtr->value<val)
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
void Linklist::displayList()
{
	Node *nodePtr;
	int count=0;
	nodePtr=head;
	cout<<"Head : "<<head->value<<endl;
	while(nodePtr!=NULL)
	{
		cout<<"List["<<count<<"] :"<<nodePtr->value<<","<<endl;
		nodePtr=nodePtr->next;
		count++;
	}
}
void Linklist::countNodes()
{
	Node *nodePtr;
	nodePtr=head;
	int counter=0;
	while(nodePtr!=NULL)
	{
		counter++;
		nodePtr=nodePtr->next;
	}
	cout<<counter<<" nodes"<<endl;
}
void Linklist::deleteNode(int val)
{
	Node *nodePtr,*previousNode;
	nodePtr=head;
	previousNode=NULL;
	while(nodePtr!=NULL && nodePtr->value!=val)
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

//void Linklist::deleteNode(int val,Node **list)
//{
//	Node *nodePtr,*previousNode;
//	nodePtr=list;
//	previousNode=NULL;
//	while(nodePtr!=NULL && nodePtr->value!=val)
//	{
//		previousNode=nodePtr;
//		nodePtr=nodePtr->next;
//	}
//	if(nodePtr)
//	{
//		previousNode->next=nodePtr->next;
//		delete nodePtr;
//	}
//	deleteNode(val,list);
//}
