#include "IntList.h"

using namespace std;

IntList::~IntList()
{
	destroy();
}

void IntList::destroy()
{
	Node *nodePtr = new Node;
	Node *temp = new Node;
	nodePtr = head;
	while (nodePtr != NULL) {
		temp = nodePtr->next;
		delete nodePtr;
		nodePtr = temp;
	}
}

void IntList::appendNum(int num)
{
	Node *nodePtr;
	nodePtr=new Node;
	Node *newNode;
	newNode=new Node;
	newNode->value=num;
	newNode->next=NULL;
	newNode->previous=NULL;
	if(isEmpty())
	{
		head=newNode;
		last=newNode;
	}
	else
	{
		last->next=newNode;
		newNode->previous=last;
		last=newNode;
		last->next=head;
		head->previous=last;
	}
}


void IntList::display()
{
	Node *nodePtr;
	nodePtr=head;
	do
	{
		cout<<nodePtr->value<<endl;
		nodePtr=nodePtr->next;
	}while(nodePtr->next!=head->next);

}

void IntList::insertNum(int num)
{
	Node *newNode = new Node;
	Node *nodePtr = new Node;
	Node *temp = new Node;
	newNode->value = num;

	if (!head)
	{
		head = newNode;
		newNode->next = NULL;
		newNode->previous = NULL;
	}
	else
	{
		nodePtr = head;
		while (nodePtr->next != NULL && num > nodePtr->value )
		{
			temp = nodePtr;
			nodePtr = nodePtr->next;
		}
		temp->next = newNode;
		nodePtr->previous = newNode;
		newNode->next = nodePtr;
		newNode->previous = temp;
	}
}

bool IntList:: searchValue(int num)
{
	Node *nodePtr = new Node;
	nodePtr = head;
	if (!head)
	{
		return false;
	}
	else
	{
		while (nodePtr != NULL && nodePtr->value != num)
		{
			nodePtr = nodePtr->next;
		}
		if (nodePtr != NULL)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}

void IntList::deleteNum(int num)
{
	Node *temp = new Node;

	if (head->value == num)
		{
			cout << "Here";
			temp = head->next;
			delete head;
			head = temp;
		}
		else
		{
			Node *nodePtr = new Node;
			Node *temp1 = new Node;

			cout << "Here1" << endl;
			nodePtr = head;
			cout << "Reached " << nodePtr->value << " \t"<<endl;

			while (nodePtr->value != num && nodePtr != NULL) {
				cout << "Reached " << nodePtr->value << " \t";
				temp = nodePtr;
				temp1 = nodePtr->next;
				nodePtr = nodePtr->next;
			}
			if (nodePtr != NULL) {
				temp->next = nodePtr->next;
				temp1->previous = temp;
				delete nodePtr;
				//nodePtr=temp;
			} else {
				cout << "Not found";
			}
		}

}



bool IntList::isEmpty()
{
	if (head)
		return false;
	else
		return true;
}
