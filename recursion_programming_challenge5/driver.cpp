#include<iostream>
using namespace std;
int mul(int,int);
int main()
{
	int x,y;
	cout<<"Enter x and y :";
	cin>>x>>y;
	cout<<mul(x,y);
	return 0;
}
int mul(int x,int y)
{
	if(x>0)
	{
		x--;
		return y+mul(x,y);
	}
	else
		return 0;
}
