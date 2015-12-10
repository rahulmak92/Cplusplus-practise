/*This is lab 2 exercise 2 code by Rahul Makwana
 * My net id is r_m338
 * and my Texas State id is A04380728*/
#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	double pi=0;
	int no_of_terms;
	cout<<"π = (4/1) - (4/3) + (4/5) - (4/7)..... "<<endl;
	cout<<"enter the number of terms to be included in computing value of π:"<<endl;
	cin>>no_of_terms;
	for(int i=1;i<=no_of_terms;i++)
	{
		if(i % 2 == 0)
		{
			pi= pi -(4.0/(2*i-1));
		}
		else
		{
			pi= pi + (4.0/(2*i-1));
		}

	}

	cout<<fixed<<setprecision(10)<<"π="<<pi;

	return 0;
}
