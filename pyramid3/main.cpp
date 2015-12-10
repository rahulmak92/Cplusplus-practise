#include <iostream>
using namespace std;
void space(int n)
{
	if(n>1)
	{
		cout<<" ";
		space(n-1);
	}
}
void star(int n)
{
	if(n>=1)
	{
		if(n%2==0)
		{
			cout<<" ";
		}
		else
		{
			cout<<"*";
		}
		star(n-1);
	}
}
void pyramid(int n,int m)
{
	if(n>0)
	{
		m++;

		if(n%2==0)
		{

		}
		else
		{
			space(n);
			star(2*m-1);
			cout<<endl;
		}
//	for(int i=1;i<=2*m-1;i++)
//			{
//				if(i%2==0)
//				{
//					cout<<" ";
//				}
//				else
//				{
//					cout<<"*";
//				}
//			}

		pyramid(n-1,m);
	}
}
void mypyramid(int n)
{
	pyramid(n,0);
}
int main()
{
	mypyramid(5);
	return 0;
}
