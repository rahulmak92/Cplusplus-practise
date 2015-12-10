#include<iostream>
#include "IntStack.h"
#include "MathStack.h"
using namespace std;

int main()
{
	int catchVar;
	MathStack stack(5);
	cout<<"Pushing 5 \n";
	stack.push(5);
	cout<<"Pushing 10 \n";
	stack.push(10);
	/*	cout<<"Pushing 15 \n";
	stack.push(15);
	cout<<"Pushing 20 \n";
	stack.push(20);
	cout<<"Pushing 25 \n";
	stack.push(25);
	cout<<"\n ------------------------"
		<<"----------------\n";
	cout<<"Lets pop now \n";
	stack.pop(catchVar);
	cout<<catchVar<<endl;
	stack.pop(catchVar);
	cout<<catchVar<<endl;
	stack.pop(catchVar);
	cout<<catchVar<<endl;
	stack.pop(catchVar);
	cout<<catchVar<<endl;
	stack.pop(catchVar);
	cout<<catchVar<<endl;  */
	stack.add();
	cout<< "the sum is :";
	stack.pop(catchVar);
	cout<<catchVar<<endl<<endl;
	cout<<"Pushing 7\n";
	stack.push(7);
	cout<<"Pushing 10\n";
	stack.push(10);
	stack.sub();
	cout<<"the difference is :";
	stack.pop(catchVar);
	cout<<catchVar<<endl;
	return 0;
}
