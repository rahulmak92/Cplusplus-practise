#include<iostream>
using namespace std;
float mileage(float,float);
int main()
{
	float capacity,miles;
	cout<<"Enter number of gallons your car can preserve:";
	cin>>capacity;
	cout<<"Enter number of miles your car can go on full tank:";
	cin>>miles;
	cout<<"Your car's mileage is "<<mileage(capacity,miles)<<endl;
}
float mileage(float cap,float mil)
{
	return mil/cap;
}
