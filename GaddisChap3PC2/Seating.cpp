#include<iostream>
#include<iomanip>
using namespace std;
float computeCharges(int,int,int);
int main()
{
	int A,B,C;
	cout<<"How many tickets for Category A ?";
	cin>>A;
	cout<<"How many tickets for Category B ?";
	cin>>B;
	cout<<"How many tickets for Category C ?";
	cin>>C;
	cout<<setprecision(2)<<fixed;
	cout<<"Your total cost for the purchase is "<<computeCharges(A,B,C);
}
float computeCharges(int a,int b,int c)
{
	return a*15+b*12+c*9;
}
