/*This is lab 2 exercise 3 code by Rahul Makwana
 * My net id is r_m338
 * and my Texas State id is A04380728*/
#include<iostream>
#include<iomanip>
using namespace std;
int main()
{

		float daily_temp;
		int counter_over_100=0;
		cout<<"Please enter the list of daily high temperatures,"<<endl;
		cout<<"enter -1 when finished:";
		cin>>daily_temp;
		while(daily_temp!=-1)
		{

			if(daily_temp >= 100)
			{
				counter_over_100++;
			}
			cin>>daily_temp;
		}
		cout<<"Days >= 100 :"<<counter_over_100<<endl;
return 0;
}
