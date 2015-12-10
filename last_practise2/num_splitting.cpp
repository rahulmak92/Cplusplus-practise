#include<iostream>
using namespace std;
void fetcher(int );
int main()
{
	int integer;
	cout<<"Enter the number:";
	cin>>integer;
	fetcher(integer);
	return 0;
}
void fetcher(int breakit)
{
	int p;
	while(breakit>0)
	{
		p=breakit%10;
		breakit=breakit/10;
		cout<<p<<endl;
	}
}
