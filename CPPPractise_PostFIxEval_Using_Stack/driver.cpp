#include "Stack.h"
#include<iostream>
using namespace std;
Stack st;
int eval(string s)
{
	int ans=0;
	int val1=0,val2=0;
	for(int i=s.size();i>=0;i--)
	{
		if(isdigit(s[i]))
		{
			s[i]=s[i]-'0';
			st.push(s[i]);
		}
		else if(s[i]=='*')
		{
			val1=st.topElement();
			st.pop();
			val2=st.topElement();
			st.pop();
			ans=val1*val2;
			st.push(ans);
		}
		else if(s[i]=='/')
		{
			val1=st.topElement();
			st.pop();
			val2=st.topElement();
			st.pop();
			ans=val1/val2;
			st.push(ans);
		}
		else if(s[i]=='+')
		{
			val1=st.topElement();
			st.pop();
			val2=st.topElement();
			st.pop();
			ans=val1+val2;
			st.push(ans);
		}
		else if(s[i]=='-')
		{
			val1=st.topElement();
			st.pop();
			val2=st.topElement();
			st.pop();
			ans=val1-val2;
			st.push(ans);
		}
	}
	return st.topElement();
}
int main()
{
	int ans=0;
	ans=eval("+-++23456");
	cout<<"Answer : "<<ans;
	return 0;
}
