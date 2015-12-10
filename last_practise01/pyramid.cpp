#include<iostream>
using namespace std;
int main()
{
	int row;
	int p=-1,z=0;
	cout<<"Enter number of rows:";
	cin>>row;
	int k=row;
	for(int i=0;i<row;i++)
	{
		p=p+2;
		z=0;
		for(int j=0;j<2*row;j++)
		{
			if(j<k-1)
			{
				cout<<" ";
			}
			else
			{
				while(z<p)
				{
					cout<<"*";
					z++;
				}
			}
		}
		k--;
		cout<<endl;
	}
	return 0;
}
