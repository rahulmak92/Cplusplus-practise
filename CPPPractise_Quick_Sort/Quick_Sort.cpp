#include<iostream>
using namespace std;
int count=0;
int partition(int[],int,int);
void quicksort(int[],int,int);

int main()
{
	int arr[7]={6,3,11,9,1,2,7};
	for(int i=0;i<7;i++)
	{
		cout<<arr[i]<<" ";
	}
	quicksort(arr,0,6);
	cout<<endl;
	for(int i=0;i<7;i++)
	{
		cout<<arr[i]<<" ";
	}

	return 0;
}
void quicksort(int arr[],int start,int end)
{
	int pivotpoint;
	if(start<end)
	{
		pivotpoint=partition(arr,start,end);
		quicksort(arr,start,pivotpoint-1);
		quicksort(arr,pivotpoint+1,end);
	}
}
int partition(int arr[],int start,int end)
{
	int mid,pivotIndex,pivotValue;
	mid=(start+end)/2;
	swap(arr[mid],arr[start]);
	pivotIndex=start;
	pivotValue=arr[start];
	for(int scan=start;scan<=end;scan++)
	{
		if(arr[scan]<pivotValue)
		{
			pivotIndex++;
			swap(arr[scan],arr[pivotIndex]);
		}
	}

	swap(arr[start],arr[pivotIndex]);
	cout<<endl;
	for(int i=0;i<7;i++)
	{
		cout<<arr[i]<<" ";
	}
	return pivotIndex;
}
