#include "Stack.h"
#include<iostream>
#include<string>
using namespace std;

const int PUSH_CHOICE=1,
			POP_CHOICE=2,
			QUIT_CHOICE=3;
void menu(int &);
void getStackSize(int &);
void pushItem(Stack<string>&);
void popItem(Stack<string>&);

int main()
{
	int stackSize;
	int choice;
	getStackSize(stackSize);
	Stack<string> stack(stackSize);
	do
	{
		menu(choice);
		if(choice!=QUIT_CHOICE)
		{
			switch(choice)
			{
			case PUSH_CHOICE: pushItem(stack);
								break;
			case POP_CHOICE: popItem(stack);
								break;
			}
		}
	}while (choice!=QUIT_CHOICE);
	return 0;
}
void getStackSize(int &size)
{
	cout<<"how big should I make the stack?";
	cin>>size;
	while(size<1)
	{
		cout<<"Enter 1 or greater :";
		cin>>size;
	}
}
void menu(int &choice)
{
	cout<<"\n What do you want to do?\n"
		<<PUSH_CHOICE
		<<"- Push an item onto the stack\n"
		<<POP_CHOICE
		<<"-Pop an item from the stack\n"
		<<QUIT_CHOICE
		<<"- Quit the program\n"
		<<"Enter your choice:";
	cin>>choice;

	while(choice <PUSH_CHOICE || choice>QUIT_CHOICE)
	{
		cout<<"Enter a valid choice:";
		cin>>choice;
	}
}
void pushItem(Stack<string> &stack)
{
	string item;
	cin.ignore();
	cout<<"\nEnter an item:";
	getline(cin,item);
	stack.push(item);
}
void popItem(Stack<string> &stack)
{
	string item = "";
	stack.pop(item);
	if(item!="")
	{
		cout<<item<<" was popped\n";
	}

}
