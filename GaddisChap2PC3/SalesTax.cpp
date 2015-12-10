#include<iostream>
using namespace std;
int main()
{
	float amount,state_tax=4,country_tax=2,total_tax;
	amount=95;
	total_tax=amount*state_tax/100 + amount*country_tax/100;
	cout<<"Total tax : "<<total_tax<<" $";
}
