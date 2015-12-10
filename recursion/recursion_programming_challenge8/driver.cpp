#include<iostream>
signed int SIZE=5;
using namespace std;
bool isMember(int [],int);
int main()
{
	int array[SIZE],ch;
	for(int i=0;i<SIZE;i++)
	{
		array[i]=i;
	}
	cout<<"Enter number to check :";
	cin>>ch;
	cout<<ch<<" is member of array is "<<isMember(array,ch);
	return 0;
}
bool isMember(int arr[],int check)
{

	if(arr[SIZE]==check)
	{
		return true;
	}
	else if(SIZE<0)
	{
		return false;
	}
	else if(arr[SIZE]!=check)
	{
		SIZE--;
		return isMember(arr,check);
	}
}
