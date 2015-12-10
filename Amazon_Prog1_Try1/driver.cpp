
#include "Stack.h"
#include <iostream>
#include <cmath>
#include <string>
using namespace std;
int *convert_to_array(int ,int);
int main()
{
	int size,val;
	int *result;
	string *resultString;
	cout<<"Enter number of digits :";
	cin>>size;
	result = new int[size];
	Stack stk1(size);
	cout<<"enter number :";
	cin>>val;
	result = convert_to_array(val,size);

	for(int i=0;i<size;i++)
	{
		stk1.push(result[i]);
	}
	cout<<"Diplaying stack :";
	stk1.displayElements();
	resultString=stk1.displayInWords();
	for(int i=0;i<size;i++)
	{
		cout<<resultString[i]<<" ";
	}
	return 0;
}
int *convert_to_array(int val,int size)
{
	int *resultArray;
	resultArray=new int[size];
	//int div=pow(10,size-1);
	for(int j=size-1;j>=0;j--)
	{
		resultArray[j]=val-((val/10)*10);
//		cout<<"Result Array = "<<resultArray[j]<<"\t";
		val = (val-resultArray[j])/10;
//		cout<<"val = "<<val<<endl;
	}
	return resultArray;
}
