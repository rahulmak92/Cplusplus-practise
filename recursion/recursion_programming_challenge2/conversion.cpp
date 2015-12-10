#include<iostream>
using namespace std;
int sign(int);
void sign1(int);
int main()
{
	int n=5;
	//cout<<sign(n)<<endl;
	sign1(n);
	return 0;
}
int sign(int n)
{
	if(n>0)
	{
		cout<<"No parking \n";
		return sign(n-1);
	}
	else
	{
		return 0;
	}
}
void sign1(int n)
{
	while(n>0)
	{
		cout<<"no parking\n";
		n--;
	}
}
