#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include<iostream>
using namespace std;
template <class T>
class LinkedList
{
	private:
			struct ListNode
			{
				T value;
				struct ListNode *next;
			};
			ListNode *head;
	public:
			LinkedList()
			{
				head=NULL;
			}
			~LinkedList();
			void appendNode(T);
			void insertNode(T);
			void deleteNode(T);
			void displayList();
};
template <class T>
void LinkedList<T>::appendNode(T newValue)
{
	ListNode *newNode;
	ListNode *nodePtr;
	newNode=new ListNode;
	newNode->value=newValue;
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
template <class T>
void LinkedList<T>::displayList()
{
	ListNode *nodePtr;
	nodePtr=head;
	while(nodePtr)
	{
		cout<<nodePtr->value<<endl;
		nodePtr=nodePtr->next;
	}
}
template <class T>
void LinkedList<T>::insertNode(T newValue)
{
	ListNode *newNode;
	ListNode *nodePtr;
	ListNode *previousNode=NULL;
	newNode=new ListNode;
	newNode->value=newValue;

	if(!head)
	{
		head=newNode;
		newNode->next=NULL;
	}
	else
	{
		nodePtr=head;
		previousNode=NULL;
		while(nodePtr!=NULL && nodePtr->value<newValue)
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
