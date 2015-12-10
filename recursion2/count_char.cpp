#include<iostream>
#include<string>
using namespace std;
int numChars(char,string,int);
int main()
{
	string str = "abcddddef";
	cout<<"The letter d appears "
		<<numChars('d',str,0) << " times.\n";
	return 0;
}
int numChars(char search,string str,int subscript)
{
	if(subscript >= str.length())
	{
		return 0;
	}
	else if(str[subscript]==search)
	{
		return 1+numChars(search,str,subscript+1);
	}
	else
	{
		return numChars(search,str,subscript+1);
	}
}
