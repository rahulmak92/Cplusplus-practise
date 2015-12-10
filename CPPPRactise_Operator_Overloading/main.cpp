#include<iostream>
#include<iomanip>
#include "Budget.h"
using namespace std;
int main()
{
	int count;
	const int NUM_DIVISIONS = 4;
	Budget divisions[NUM_DIVISIONS];

	for(count=0;count<NUM_DIVISIONS;count++)
	{
		double budgetAmount;
		cout<<"Enter the budget request for divison :";
		cout<<(count+1)<<" : ";
		cin>>budgetAmount;
		divisions[count].addBudget(budgetAmount);
	}
		cout<<fixed<<showpoint<<setprecision(2);
		cout<<"\nHere are the division budget requests:\n";
		for(count=0;count<NUM_DIVISIONS;count++)
		{
			cout<<"\t Divisions "<<(count+1)<<"\t$";
			cout<<divisions[count].getDivisionBudget()<<endl;
		}
		cout<<"\tTotal Budget Requests:\t$";
		cout<<divisions[0].getCorpBudget()<<endl;

		return 0;
}
