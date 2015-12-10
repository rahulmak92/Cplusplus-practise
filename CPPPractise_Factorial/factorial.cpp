#include<iostream>
using namespace std;
int fact(int);
int factorial(int);
int main()
{
	int value;
	cout<<"Enter value :";
	cin>>value;
	cout<<"Factorial1 is "<<fact(value)<<endl;
	cout<<"Factorial2 is "<<factorial(value);
	return 0;
}
int fact(int n)
{
	int result=0;
	if(n == 0)
	{
		cout<<"Factorial of 0 is 1 so.. ";
		return 1;
	}
	if(n == 1)
	{
		return 1;
	}
	else
	{
		result = n * fact(n-1);
	}
	return result;
}
int factorial(int n)
{
	int result=1;

	while(n>0)
	{
		result = result * n;
		n--;
	}
	return result;
}
