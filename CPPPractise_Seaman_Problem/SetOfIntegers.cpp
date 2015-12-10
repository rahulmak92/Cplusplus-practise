#include "SetOfIntegers.h"
#include<iostream>
using namespace std;
Set::Set()
{
	count=0;
	size=0;
	elements= new int[size];
}
Set::Set(int given_size)
{
	size=given_size;
	count=0;
	elements= new int[size];
}
Set::Set(const Set &obj) //copy constructor
{
	count=obj.count;
	size=obj.size;
	elements=new int[size];
	for(int i=0;i<size;i++)
	{
		elements[i]=obj.elements[i];
	}
}
void Set::insert(int val)
{
	if(!check(val))
	{
		if(count<=size)
		{
			elements[count]=val;
			count++;
		}
		else if(count>size)
		{
			cout<<"Size exceeded!!"<<endl;
		}
	}
	else
	{
		cout<<endl<<val<<" already exists!"<<endl;
	}
}
bool Set::check(int val) const
{
	int cnt=0;
	while(cnt<size)
	{
		if(elements[cnt]==val)
		{
			return true;
		}
		cnt++;
	}
	return false;
}
void Set::displaySet()
{
	cout<<endl;
	cout<<"there are "<<count
		<<" elements in Set!";
	cout<<endl<<"< ";
	for(int i=0;i<count;i++)
	{
		cout<<elements[i]<<",";
	}
	cout<<">"<<endl;
}
Set::~Set()
{
	delete [] elements;
}
Set Set::operator+(const Set &right)
{
	int new_size=size+right.size;
	Set result(new_size);
	for(int i=0;i<count;i++)
	{
		result.insert(elements[i]);
	}
	for(int i=0;i<right.count;i++)
	{
		result.insert(right.elements[i]);
	}
	return result;
}
Set Set::operator=(const Set &right)
{
	int *old=elements;
	size=right.size;
	elements=new int[size];
	count=right.count;
	for(int i=0;i<right.size;i++)
	{
		elements[i]=right.elements[i];
	}
	delete [] old;
	return *this;
}
Set Set::operator*(const Set &right)
{
	Set result(right.size);
	for(int j=0;j<right.size;j++)
	{
		for(int i=0;i<size;i++)
		{
			if(elements[i]==right.elements[j])
			{
				result.insert(right.elements[j]);
			}
		}
	}
	return result;
}
Set Set::operator -(const Set &right)
{
	Set result(size);
	Set temp = *this * right;
	for(int i=0;i<temp.size;i++)
	{
		for(int j=0;j<size;j++)
		{
			if(elements[j]!=temp.elements[i])
			{
				result.insert(elements[j]);
			}
		}
	}
	delete [] temp.elements;
	return result;
}
