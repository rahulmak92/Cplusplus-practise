#include "IntList.h"
IntList::IntList() {
    head = NULL;
}

IntList::~IntList() {
    Node *p = head;
    Node *n;
    while (p!=NULL) {
        n = p->next;
        delete p;
        p = n;
    }
}

void IntList::appendNode(int num) {
    Node *newNode;
    newNode = new Node;
    newNode->value = num;
    newNode->next = NULL;
    if (head==NULL)
        head = newNode;
    else {
        Node *p = head;
        while (p->next!=NULL) {
            p = p->next;
        }
        p->next = newNode;
    }
}
int IntList::countOddNodes(Node *nodePtr,int count)
{
	if(nodePtr)
	{
		if(nodePtr->value%2!=0)
		{
			count++;
			return countOddNodes(nodePtr->next,count);
		}
		else
		{
			return countOddNodes(nodePtr->next,count);
		}
	}
	else
	{
		return count;
	}

}
