#include "Stack.h"
#include <iostream>
using namespace std;
Stack::Stack(int size)
{
	stackSize=size;
	top=-1;
	stackArray = new int[stackSize];
}
bool Stack::isFull()
{
	if(top>=stackSize)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool Stack::isEmpty()
{
	if(top==-1)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void Stack::push(int val)
{
	if(!isFull())
	{
		top++;
		stackArray[top]=val;
//		cout<<"Added "<<val<<" at "<<top<<endl;
	}
	else
	{
		cout<<"Full"<<endl;
	}
}
void Stack::displayElements()
{
	cout<<endl;
	for(int i=top;i>=0;i--)
	{
		if(i==top)
		{
			cout<<"position["<<i<<"] "<<stackArray[i]<<"<--top"<<endl;
		}
		else
		{
			cout<<"position["<<i<<"] "<<stackArray[i]<<endl;
		}
	}
}

string *Stack::displayInWords()
{
	int count=0;
	string *resultArray;
	resultArray = new string[top];
	for(int i=top;i>=0;i--)
	{
		count++;
		if(count == 1)
		{
			if(stackArray[i-1]==1)
			{
			resultArray[i]=disp_1_single(stackArray[i]);
			count++;
			i--;
			}
			else
			{
				cout<<"this one too";
				resultArray[i]=disp_single(stackArray[i]);
			}
		}
		else if(count == 2)
		{
			resultArray[i]=disp_ten(stackArray[i]);
		}
		else if(count == 3)
		{
			resultArray[i]=disp_hundreds(stackArray[i]);
		}
		else if(count == 4)
		{
			resultArray[i]=disp_thousands(stackArray[i]);
		}
	}
	return resultArray;
}
string Stack::disp_1_single(int val)
{
	string result;
		switch(val)
		{
		case 1 :
			result="Eleven";
					break;
		case 2 :
			result="Twelve";
					break;
		case 3 :
			result="Thirteen";
					break;
		case 4 :
			result="Fourteen";
					break;
		case 5 :
			result="Fifteen";
					break;
		case 6 :
			result="Sixteen";
					break;
		case 7 :
			result="Seventeen";
					break;
		case 8 :
			result="Eighteen";
					break;
		case 9 :
			result="Ninteen";
					break;
		case 0 :
			result="Ten";
				break;
		default:
				cout<<"Error";
				break;
		}
		return result;
}
string Stack::disp_thousands(int val)
{
	string result;
	if(val!=0)
	{
		result = disp_single(val) + " Thousand";
	}
	else
	{
		result=" ";
	}
	return result;
}
string Stack::disp_hundreds(int val)
{
	string result;
	if(val!=0)
	{
		result = disp_single(val) + " hundred";
	}
	else
	{
		result = " ";
	}
	return result;
}
string Stack::disp_ten(int val)
{
	string result;
	switch(val)
	{
	case 1 :
		result="Ten";
				break;
	case 2 :
		result="Twenty";
				break;
	case 3 :
		result="Thirty";
				break;
	case 4 :
		result="Fourty";
				break;
	case 5 :
		result="Fifty";
				break;
	case 6 :
		result="Sixty";
				break;
	case 7 :
		result="Seventy";
				break;
	case 8 :
		result="Eighty";
				break;
	case 9 :
		result="Ninty";
				break;
	case 0 :
		result=" ";
			break;
	default:
			cout<<"Error";
			break;
	}
	return result;
}
string Stack::disp_single(int val)
{
	string result;
	switch(val)
	{
	case 1 :
		result="One";
				break;
	case 2 :
		result="Two";
				break;
	case 3 :
		result="Three";
				break;
	case 4 :
		result="Four";
				break;
	case 5 :
		result="Five";
				break;
	case 6 :
		result="Six";
				break;
	case 7 :
		result="Seven";
				break;
	case 8 :
		result="Eight";
				break;
	case 9 :
		result="Nine";
				break;
	case 0 :
		result=" ";
			break;
	default:
			cout<<"Error";
			break;
	}
	return result;
}
