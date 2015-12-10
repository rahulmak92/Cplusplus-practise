// Exercise 3 driver file
// Lab 9
// Fall 2014

#include <iostream>
using namespace std;

#include "IntStack.h"

IntStack stack;

int evalPostFix(string s)
{
        int result,val1,val2;
        for(int i=0;i<s.size();i++)
        {
                if(isdigit(s[i]))
                {
                	//cout<<"Here at"<<s[i]<<"\t";
                        s[i]=s[i]-'0';
                        stack.push(s[i]);
                }
                else if(s[i]=='/')
                {
                        val1=stack.pop();
                        val2=stack.pop();
                        result=val2/val1;
                        stack.push(result);
                }
                else if(s[i]=='*')
                {
                        val1=stack.pop();
                        val2=stack.pop();
                        result=val2*val1;
                        stack.push(result);
                }
                else if(s[i]=='+')
                {
                        val1=stack.pop();
                        val2=stack.pop();
                        result=val2+val1;
                        stack.push(result);
                }
                else if(s[i]=='-')
                {
                        val1=stack.pop();
                        val2=stack.pop();
                        result=val2-val1;
                        stack.push(result);
                }
        }
        return stack.pop();
}

int main()
{
    cout << evalPostFix("84/") << " (should be 2)" << endl;
    cout << evalPostFix("84*") << " (should be 32)" << endl;
    cout << evalPostFix("12+84-*") << " (should be 12)" << endl;
    cout << evalPostFix("8412+-*") << " (should be 8)" << endl;
    return 0;
}

