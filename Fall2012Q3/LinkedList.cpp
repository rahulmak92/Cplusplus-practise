#include "LinkedList.h"
using namespace std;
void LinkedList::addNode(int val)
{
	Node *newNode;
	newNode = new Node;
	newNode->data = val;
	newNode->next = NULL;
	if(!head)
	{
		head=newNode;
	}
	else
	{
		Node *nodePtr,*previousNode;
		nodePtr=head;
		previousNode=NULL;
		while(nodePtr && nodePtr->data < val)
		{
			previousNode=nodePtr;
			nodePtr=nodePtr->next;
		}
		if(!previousNode)
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
void LinkedList::displayList()
{
	Node *nodePtr;
	nodePtr=head;
	while(nodePtr!=NULL)
	{
		cout<<nodePtr->data<<",";
		nodePtr=nodePtr->next;
	}
	cout<<endl;
}
void LinkedList::deleteNode(int val)
{
	Node *nodePtr,*previousNode;
	previousNode=NULL;
	nodePtr=head;
	while(nodePtr && nodePtr->data != val)
	{
		previousNode=nodePtr;
		nodePtr=nodePtr->next;
	}
	if(previousNode==NULL)
	{
		head=nodePtr->next;
		delete nodePtr;
	}
	else
	{
		previousNode->next=nodePtr->next;
		delete nodePtr;
	}
}
void LinkedList::findMode()
{

	Node *nodePtr,*prev;
	nodePtr=head;
	prev=NULL;
	int tempCount=1;
	int MAX_COUNT=0;
	int element=0;
	while(nodePtr)
	{
		prev=nodePtr;
		Node *temp=prev;
		while(temp && prev->data == temp->data)
		{
			tempCount++;
			temp=temp->next;
//			cout<<prev->data<<" count is "<<tempCount<<"\t";
		}
		if(tempCount>MAX_COUNT)
		{

			MAX_COUNT=tempCount;
			element=prev->data;
			tempCount=0;
//			cout<<"Max count "<<MAX_COUNT<<" for"<<element<<endl;
		}
		nodePtr=temp;
	}
	cout<<element<<endl;
}
