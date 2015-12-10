#include<iostream>
using namespace std;
int binarySearch(int [],int,int,int);
const int SIZE=20;
int main()
{
	int tests[SIZE]={101,142,147,189,199,207,222,
					234,289,296,310,319,388,394,
					417,429,447,521,536,600};
	int empID;
	int results;
	cout<<"Enter the employee ID you wish to search for:";
	cin>>empID;
	results=binarySearch(tests,0,SIZE-1,empID);
	if(results==-1)
		cout<<"That number does not exists in the array.\n";
	else
	{
		cout<<"That ID is found at element "<<results;
		cout<<" in the array\n";
	}
	return 0;
}
int binarySearch(int array[],int first,int last,int value)
{
	int middle;
	if(first>last)
		return -1;
	middle=(first+last)/2;
	if(array[middle]==value)
		return middle;
	if(array[middle]<value)
		return binarySearch(array,middle+1,last,value);
	else
		return binarySearch(array,first,middle-1,value);
}
