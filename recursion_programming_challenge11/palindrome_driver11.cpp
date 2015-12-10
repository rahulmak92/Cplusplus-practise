#include<string>
#include<iostream>
using namespace std;
bool ifPalindrome(string,int,int);
int main()
{
	string check_string;
	bool decision;
	cout<<"enter the string to check \n"
		<<"if its a palindrome or not :";
	cin>>check_string;
	cout<<"\n";
	decision=ifPalindrome(check_string,check_string.size()-1,0);
	if(decision==1)
	{
		cout<<"It is palindrome";
	}
	else
	{
		cout<<"Its not a Palindrome!";
	}
	return 0;
}
bool ifPalindrome(string s,int size,int first)
{
	if(size>first)
	{
		if(s[first]==s[size])
		{
			first++;
			size--;
			return ifPalindrome(s,size,first);
		}
		else
		{
			return false;
		}
	}
	else
	{
		return true;
	}
}
