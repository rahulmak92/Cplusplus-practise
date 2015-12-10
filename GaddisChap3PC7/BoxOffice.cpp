#include<iostream>
#include<iomanip>
using namespace std;
void compute(int,int);
int main()
{
	string Movie;
	int adult,child;
	cout<<"What was the movie name:";
	cin>>Movie;
	cout<<"How many adult:";
	cin>>adult;
	cout<<"How many child:";
	cin>>child;
	cout<<"Movie Name:"<<setw(20)<<Movie<<endl;
	compute(adult,child);
	return 0;
}
void compute(int a,int c)
{
	float gross_profit,net_profit,distributor;
	gross_profit=a*10+c*6;
	net_profit=gross_profit*0.2;
	distributor=gross_profit-net_profit;
	cout<<"Adults Tickets Sold:"<<setw(20)<<a<<endl;
	cout<<"Child Tickets Sold:"<<setw(20)<<c<<endl;
	cout<<"Gross Box Office Profit:"<<setw(20)<<"$"<<setprecision(2)<<fixed<<gross_profit<<endl;
	cout<<"Net Box Office Profit:"<<setw(20)<<"$"<<setprecision(2)<<fixed<<net_profit<<endl;
	cout<<"Amount paid to distributor:"<<setw(20)<<"$"<<setprecision(2)<<fixed<<distributor<<endl;

}
