#include<iostream>
#include<iomanip>
using namespace std;
float average(int []);
int main()
{
	int arr[5];
	cout<<"Enter 5 test scores : ";
	for(int i=0;i<5;i++)
	{
		cin>>arr[i];
	}
	cout<<setprecision(1)<<fixed;
	cout<<"Your average for these tests is :"<<average(arr);
}
float average(int scores[])
{
	int sum=0;
	for(int i=0;i<5;i++)
	{
		sum=sum+scores[i];
	}
	return sum/5;
}
