#include<iostream>
using namespace std;
void reverser(string,int);
int main()
{
	string val;
	cout<<"enter the string :";
	cin>>val;
	cout<<"Reversed =\"";
	reverser(val,val.size());
	cout<<"\"";
	return 0;
}
void reverser(string s,int size)
{
	if(size>=0)
	{
		cout<<s[size];
		size--;
		reverser(s,size);
	}
	else
	{

	}
}
