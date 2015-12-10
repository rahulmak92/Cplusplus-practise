#include "DLinkedList.h"
#include <iostream>
using namespace std;
int main()
{
	DLinkedList d;
	d.insertAfter(5);
	d.insertAfter(7);
	d.insertBefore(2);
	d.insertBefore(2);
	d.insertAfter(9);
	d.printData();
	cout<<"Popped "<<d.popLast()<<endl;
	cout<<"New "<<endl;
	d.printData();
	cout<<"Popped from front "<<d.popFirst()<<endl;
	cout<<"updated"<<endl;
	d.printData();
	return 0;
}






void methodA()
{
	cout<<methodB();
}
int methodB()
{
	return 1 + methodC();
}
int methodC()
{
	int newarray[5];
	newarray=methodD(); // 8 elements being passed to an array of size 5
	int sum=0;
	for (int a=0;a<5;a++)
	{
		sum=sum+newarray[a];
	}
	return sum;
}
int* methodD()
{
	int arr[8];
	for(int i=0;i<5;i++) // array size is 8
	{
		cin<<arr[i];
	}
	return arr;
}




















