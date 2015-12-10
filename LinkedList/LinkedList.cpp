#include "LinkedList.h"
LinkedList::LinkedList()
{
	head=NULL;
}
int LinkedList::getData()
{

	return head->data;
}
