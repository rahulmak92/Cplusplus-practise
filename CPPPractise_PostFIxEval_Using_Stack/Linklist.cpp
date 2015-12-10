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
		while(nodePtr!=NULL)
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
int Linklist::countNodes()
{
	Node *nodePtr;
	nodePtr=head;
	int counter=0;
	while(nodePtr!=NULL)
	{
		counter++;
		nodePtr=nodePtr->next;
	}
	return counter;
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
	if(previousNode)
	{
		previousNode->next=nodePtr->next;
		delete nodePtr;
	}
}
int Linklist::getLastNode()
{
	Node *nodePtr;
	Node *previousNode=NULL;
	nodePtr=head;
	while(nodePtr)
	{
		previousNode=nodePtr;
		nodePtr=nodePtr->next;
	}
	if(previousNode==NULL)
	{
		cout<<"Empty List";
		return 0;
	}
	else
	{
		return previousNode->value;
	}
}
void Linklist::display_descending()
{
	int index=0;
	Node *nodePtr;
	nodePtr=head;
	int size=countNodes();
	int arr[size];
	for(int i=0;i<size;i++)
	{
		arr[i]=nodePtr->value;
		nodePtr=nodePtr->next;
	}
	for(index=size-1;index>=0;index--)
	{
		cout<<"\t"<<arr[index]<<endl;
	}
}
