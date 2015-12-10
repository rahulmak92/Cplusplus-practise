#include<iostream>
using namespace std;
int var=0;
int gcd(int,int);
int main()
{
	int num1,num2;
	cout<<"Enter two integers: ";
	cin>>num1>>num2;

	cout<<"the greatest common divisor of "<<num1;
	cout<<" and "<< num2<<" is ";
	cout<<gcd(num1,num2)<<endl;
	cout<<var<<" times function iterated.\n";
	return 0;
}
int gcd(int x,int y)
{
	var++;
	cout<<"\nInteration num :"<<var<<endl;
	if(x%y==0)
	{
		cout<<"\n----if statement----\n";
		cout<<"Val1 :"<<x<<endl;
		cout<<"Val2 :"<<y<<endl;
		return y;
	}
	else
	{
		cout<<"\n----else statement----\n";
		cout<<"Val1 :"<<x<<endl;
		cout<<"Val2 :"<<y<<endl;
		return gcd(y,x%y);
	}
}
