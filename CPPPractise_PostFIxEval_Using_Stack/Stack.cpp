#include "Stack.h"
Stack::Stack()
{
	Linklist();
}
void Stack::push(int item)
{
	if(!isFull())
	{
		list.insertNode(item);
	}
	else
	{
		cout<<"It is full";
	}
}
void Stack::display()
{
	cout<<"Stack :"<<endl;
	list.display_descending();
}
void Stack::pop()
{
	int this_node=0;
	if(!isEmpty())
	{
		this_node=list.getLastNode();
		list.deleteNode(this_node);
	}
	else
	{
		cout<<"Stack is empty!!";
	}
}
bool Stack::isEmpty()
{
	if(list.countNodes()>0)
	{
		return false;
	}
	else
	{
		return true;
	}
}
bool Stack::isFull()
{
	return false;
}
int Stack::topElement()
{
	return list.getLastNode();

}
