#include<iostream>
using namespace std;
float reciproc(int);
int main()
{
	int n;
	cout<<"Enter n's odd length:";
	cin>>n;
	cout<<reciproc(n);
	return 0;
}
float reciproc(int n)
{
	float sum;
	if(n!=1)
	{
		sum=sum+1/reciproc(n-2);
	}
	else
	{
		sum = sum + 1;
	}
	return sum;
}
