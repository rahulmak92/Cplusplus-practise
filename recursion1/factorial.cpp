#include<iostream>
using namespace std;
int factorial(int);
int main()
{
	int number;

	cout<<"Enter an integer value and I will display\n";
	cout<<"its factorial: ";
	cin>>number;

	cout<<"the factorial of "<<number<<" is ";
	cout<<factorial(number)<<endl;
	return 0;
}
int factorial(int n)
{
	if(n==0)
		return 1;
	else
		return n*factorial(n-1);
}
