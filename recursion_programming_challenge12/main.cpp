#include<iostream>
using namespace std;
int Ack(int,int);
int main()
{
/*	cout<<Ack(0,0)<<endl;
	cout<<Ack(0,1)<<endl;
	cout<<Ack(1,1)<<endl;
	cout<<Ack(1,2)<<endl;
	cout<<Ack(1,3)<<endl;
	cout<<Ack(2,2)<<endl;*/
	cout<<Ack(4,5)<<endl;
	return 0;
}
int Ack(int m,int n)
{
	cout<<"m="<<m<<",n="<<n<<endl;
	if(m==0)
		return n+1;
	else if(n==0)
		return Ack(m-1,1);
	else
		return Ack(m-1,Ack(m,n-1));
}
