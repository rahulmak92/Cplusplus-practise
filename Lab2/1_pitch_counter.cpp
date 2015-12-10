/*This is lab 2 exercise 1 code by Rahul Makwana
 * My net id is r_m338
 * and my Texas State id is A04380728*/
#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	int age=0,pitches;


	cout<<"Enter your age:"<<endl;
	cin>>age;
	if(age<7 || age>18)
	{
		cout<<"Please enter your age in valid range: 7-18"<<endl;
	}
	else
	{
	cout<<"Great! How many pitches have you thrown? :"<<endl;
	cin>>pitches;
	if(age>=7 && age<=8)
	{
		if(pitches>=21 && pitches<=35)
		{
				cout<<"you have to rest for 1 day"<<endl;
		}
		else if(pitches>=36 && pitches<=50)
		{
				cout<<"you have to rest for 2 day"<<endl;
		}

		if(pitches>50)
		{
			cout<<"Over Limit Pitches"<<endl;
			if(pitches>=51 && pitches<=65)
			{

				cout<<"you must rest for 3 day"<<endl;
			}
			else if(pitches>=66)
			{
				cout<<"you have to rest for 4 day"<<endl;
			}
		}
		else
		{
			cout<<"You are Well balanced!"<<endl;
		}
	}
	else if(age>=9 && age<=10)
	{
		if(pitches>75)
		{
			cout<<"Over Limit Pitches"<<endl;
			cout<<"you have to rest for 4 day"<<endl;
		}

		else
		{
			cout<<"You are Well balanced!"<<endl;
		}
	}
	else if(age>=11 && age<=12)
	{
		if(pitches>85)
		{
			cout<<"Over Limit Pitches"<<endl;
			cout<<"you have to rest for 4 day"<<endl;
		}
		else
		{
			cout<<"You are Well balanced!"<<endl;
		}
	}
	else if(age>=13 && age<=16)
	{
		if(pitches>95 && age<=14)
		{
			cout<<"Over Limit Pitches"<<endl;
			cout<<"you have to rest for 4 day"<<endl;

		}
		else if(pitches>95 && age>14)
		{
			cout<<"Over Limit Pitches"<<endl;
			cout<<"you have to rest for 4 day"<<endl;
		}
		else
		{
			cout<<"You are Well balanced!"<<endl;
		}
	}
	else if(age>=17 && age<=18)
	{
		if(pitches>105)
		{
			cout<<"Over Limit Pitches"<<endl;
			cout<<"you have to rest for 4 day"<<endl;
		}
		else
		{
			cout<<"You are Well balanced!"<<endl;
		}
	}
	}
return 0;
}
