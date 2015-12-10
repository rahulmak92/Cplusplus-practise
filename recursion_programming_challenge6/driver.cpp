#include<iostream>
using namespace std;
int pow(int,int);
int main()
{
	int num,power;
	cout<<"Enter number :";
	cin>>num;
	cout<<"Enter power :";
	cin>>power;
	cout<<pow(num,power);
	return 0;
}
int pow(int num,int power)
{
	if(power>0)
	{
		power--;
		return num*pow(num,power);
	}
	else
		return 1;
}
