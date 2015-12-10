#include<iostream>
using namespace std;
int facto(int &);
int main()
{
	int val=0,temp,ans=1;
	cout<<"Enter the val: ";
	cin>>val;
	for(int i=val;i>0;i--)
	{
		temp=facto(i);
		ans=ans*temp;
	}
	cout<<ans;
	return 0;
}
int facto(int &val)
{
	int ans=1;
	if(val<=0)
	{
		return ans*1;
	}

	ans=val*(val-1);
	val--;
	return ans;
}
