#include "NumberList.h"
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

NumberList :: ~NumberList()
{
	ListNode *nodePtr;
	ListNode *nextNode;

	nodePtr = head;

	while(nodePtr != NULL)
	{
		nextNode = nodePtr -> next;
		delete nodePtr;
		nodePtr = nextNode;
	}
}


void NumberList :: appendNode(double num)
{
	ListNode *newNode;
	ListNode *nodePtr;

	newNode = new ListNode;
	newNode -> value = num;
	newNode -> next = NULL;

	if(!head)
		head = newNode;
	else
	{
		nodePtr = head;

		while(nodePtr -> next)
			nodePtr = nodePtr -> next;
		nodePtr -> next = newNode;

	}

}

void NumberList :: insertNode(double num)
{
	ListNode *newNode;
	ListNode *nodePtr;
	ListNode *previousNode = NULL;

	newNode = new ListNode;
	newNode -> value = num;

	if(!head)
	{
		head = newNode;
		newNode -> next = NULL;
	}
	else
	{
		nodePtr = head;

		while(nodePtr != NULL && nodePtr-> value < num )
		{
			previousNode = nodePtr;
			nodePtr = nodePtr -> next;
		}

		if(previousNode == NULL)
		{
			nodePtr -> next = newNode;
			newNode -> next = NULL;
		}
		else
		{
			previousNode -> next = newNode;
			newNode -> next = nodePtr;
		}
	}
}

void NumberList :: deleteNode(double num)
{
	ListNode *nodePtr;
	ListNode *tempNode;

	if(!head)
		return;

	if(head -> value == num)
	{
		nodePtr = head -> next;
		delete head;
		head = nodePtr;
	}
	else
	{
		nodePtr = head;

		while(nodePtr !=NULL && nodePtr -> value != num)
		{
			tempNode = nodePtr;
			nodePtr = nodePtr -> next;
		}

		if(nodePtr)
		{
			tempNode -> next = nodePtr -> next;
			delete nodePtr;
		}
	}
}

void NumberList :: displayList() const
{
	ListNode *nodePtr;

	nodePtr = head;

	int i = 0;

	while(nodePtr)
	{
		cout <<"Position = "<<i << " ----> " << nodePtr->value << endl;

		nodePtr = nodePtr -> next;
		i++;
	}
}

/*************** To find Maximum Node ******************/
double NumberList :: maxNode(ListNode *p)
{
	if(!p)
		return 0;

	else if(p->next == NULL)
		return p->value;

	else
	{
		double x = maxNode(p->next);
		if(x > p->value)
			return x;
		else
			return p->value;
	}
}

/*************** To find Minimum Node ******************/
double NumberList :: minNode(ListNode *p)
{
	if(!p)
		return 0;

	else if(p->next == NULL)
		return p->value;

	else
	{
		double x = minNode(p->next);
		if(x < p->value)
			return x;
		else
			return p->value;
	}
}

/*************** isSorted - Yes or No ******************/
bool NumberList :: isSorted(ListNode *p)
{
	if(p==NULL)
		return true;

	else if(p->next == NULL)
		return true;

	else
		return (p->value < p->next->value) && isSorted(p->next);
}

/*************** Total Sum of all node's value ******************/
double NumberList :: totalSum(ListNode *p)
{
	if(!p)
		return 0;

	if(p->next ==NULL)
		return p->value;

	else
	{
		return (p->value) + totalSum(p->next);
	}
}

/*************** Display the Reverse List ******************/
void NumberList :: reverseList(ListNode *p)
{
	if(p != NULL)
	{
		reverseList(p->next);
		cout << p->value << " ";
	}
}

/*************** Occurance of a perticular Node ******************/
int NumberList :: nodeOccurrence(ListNode *p, double x)
{
	int count = 0;
	while(p)
	{
		if(p->value == x)
			count ++;
		p = p->next;
	}
	return count;
}

int NumberList :: nodeOccurrence(double x)
{
	return nodeOccurrence(head, x);
}

/**************** Remove Duplicates *************************/
void NumberList :: removeDuplicates(ListNode *p)
{

	ListNode *temp, *temp1;
	while(p->next != NULL)
	{
		if(p->value == p->next->value)
		{
			double val = p->value;
			temp1 = p;
			while(p->next != NULL && p->value == val)
			{
				cout<<"Doing for "<<p->value<<"\t";
				temp = p;
				p = p->next;
			}
			cout<<endl;
			//cout<<"Value of P->next "<<p->next->value<<endl;
			if(p->next != NULL)
			{
				temp1 -> next = p;
			}
			else
			{
				temp1->next=NULL;
			}
			//p= p->next;
		}
		else
		{

			p = p->next;

		}
	}
}
/**************** Remove Duplicates *************************/
void NumberList :: removeDuplicates1(ListNode *p)
{

}

/**************** Count of Nodes *************************/
int NumberList :: count(ListNode *p)
{
	if(p!=NULL)
		return 1 + count(p->next);
}


/**************** Sort the List *************************/
void NumberList :: sort(ListNode *p)
{
	ListNode *temp = p;
	int c = count(p);
	while(c >0)
	{
		p = temp;
		while (p->next!=NULL)
		{
			if(p->value < p->next->value)
			{
				p = p->next;
			}
			else
			{
				swap(p->value, p->next->value);
				p=p->next;
			}
		}
		c--;
	}
}
