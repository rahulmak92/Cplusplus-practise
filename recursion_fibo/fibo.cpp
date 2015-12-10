#include<iostream>
using namespace std;
int fibo(int);
int main()
{
	int value;
	cout<<"Enter a number: ";
	cin>>value;
	for(int i=0;i<value;i++)
	{
		cout<<fibo(i)<<" ";
		cout<<endl;
	}
	return 0;
}
int fibo(int n)
{
	if(n<=0)
	{
		return 0;
	}
	else if(n==1)
	{
		return 1;
	}
	else
		return fibo(n-1)+fibo(n-2);
}
