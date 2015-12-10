#include "DLinkedList.h"
using namespace std;
void DLinkedList::insertAfter(int val)
{
	Node *newNode = new Node();
	newNode->data=val;
	newNode->next=NULL;
	newNode->prev=NULL;
	if(head==NULL)
	{
		head=newNode;
		tail=newNode;
	}
	else
	{
		tail->next=newNode;
		newNode->prev=tail;
		tail=newNode;
	}


}
void DLinkedList::insertBefore(int val)
{
	Node *newNode = new Node();
	newNode->data=val;
	newNode->next=NULL;
	newNode->prev=NULL;
	Node *tempNode;
	if(head==NULL)
	{
		head=newNode;
		tail=newNode;
	}
	else
	{
		newNode->next=head;
		head->prev=newNode;
		head=newNode;
	}

}
int DLinkedList::popLast()
{
	int val=0;
	Node *temp;
	Node *toDel;
	toDel=tail;
	val=tail->data;
	temp=tail->prev;
	tail=temp;
	tail->next=NULL;
	delete toDel;

	return val;
}
int DLinkedList::popFirst()
{
	int val=0;
	val=head->data;
	head=head->next;

	return val;
}
void DLinkedList::printData()
{
	Node *nodePtr;
	nodePtr=head;
	while(nodePtr)
	{
		cout<<nodePtr->data<<endl;
		nodePtr=nodePtr->next;
	}

}
