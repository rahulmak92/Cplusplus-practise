#include"Station.h"
#include"Carrier.h"
#include<iostream>
#include<time.h>
using namespace std;

void update_waiting(Station &s, int &w);
void check_if_full(Carrier &c,int &c1,int &c2,int &c3,Station &s0,Station &s1);
void check_for_collision(Carrier &c,int &count_one,int message_one,Station &s,int i,int &collision);
void double_check(Station &s, int &collision, Carrier &c);

int main()
{
	Station s0, s1;
	int middle = 4;
	int latency_one=0,latency_two=0,latency_three=0;
	int success_one =0, success_two = 0, success_three=0;
	int message_one=0, message_two=0,message_three=0,count_one=0,count_two=0,count_three=0;
	int s0_waiting=0,s1_waiting=0, s2_waiting=0;
	int collision_count_one=0,collision_count_two=0,collision_count_three=0;
	int s0_collision = 0,s1_collision = 0;
	int size = 7;
	int attempted_messages=0;
	Carrier c(size,middle);


	for (int i = 0; i < 20; i++)//tick loop
	{
		for (int j = 0; j < 2; j++)
		{
			if (j == 0 && s0_collision == 0)
			{
				if(s0.its_transmitting())
				{
					if(c.get_one() ==4)
					{
						c.is_full();
						attempted_messages++;
						s0.set_collision(1);
						s0_collision = s0.get_r4();
					}
					else
					{
						latency_one++;
						c.add_bit(0,count_one,message_one);
						count_one++;
					}
					//finish transmission of station 0
				
					if(count_one == size + message_one && c.get_three()!=4)
					{
						c.is_full();
						latency_one++;
						success_one++;
						s0.end_transmit();
						c.inc_success();
						count_one = 0;
					}
				}
				//starts transmission of station 
				else if(!s0.is_waiting() && !s0.its_transmitting())
				{
					if(s0_waiting == -1 || s0.get_r1()>.9)
					{
						if(c.is_one_free())
						{
							latency_one++;
							attempted_messages++;
							s0_waiting = 0;
							message_one =s0.get_r2();
							s0.start_transmit();
							c.add_bit(0,count_one,message_one);
							count_one++;
						}
						else
						{
							s0.set_waiting_status(1);
							s0_waiting=s0.get_r3();
						}
					}
				}
			}
			if(j ==1 && s1_collision == 0)
			{
				if(s1.its_transmitting())
				{
					if(c.get_two()==4)
					{
						attempted_messages++;
						s1.set_collision(1);
						s1_collision = s1.get_r4();
					}
					else
					{
						latency_two++;
						c.add_bit(middle,count_two,message_two);
						count_two++;
					}
				
					//finish transmission
					if(count_two+middle == size + message_two && c.get_one()!=4 && c.get_three()!=4)
					{
						latency_two++;
						success_two++;
						s1.end_transmit();
						c.inc_success();
						count_two = 0;
					}
				}
				//starts to transmit if r1 > .9
				else if(!s1.is_waiting() && !s1.its_transmitting())
				{
					if(s1_waiting == -1 || s1.get_r1() >.9)
					{
						if(c.is_two_free())
						{
							latency_two++;
							attempted_messages++;
							s1_waiting = 0;
							message_two=s1.get_r2();
							s1.start_transmit();
							c.add_bit(middle,count_two,message_two);
							count_two++;
						}
						else
						{
							s1.set_waiting_status(1);
							s1_waiting = s1.get_r3();
						}
					}
				}
			}}
		check_for_collision(c,count_one,message_one,s0,0,s0_collision);
		check_for_collision(c,count_two,message_two,s1,middle,s1_collision);

		double_check(s0,s0_collision,c);
		double_check(s1,s1_collision,c);

		check_if_full(c,count_one,count_two,count_three,s0,s1);

		update_waiting(s0,s0_waiting);
		update_waiting(s1,s1_waiting);

		
		if(s0_collision >0)
		{
			s0_collision--;
			latency_one++;
		}
		if(s1_collision >0)
		{
			s1_collision--;
			latency_two++;
		}
	}
	double m = attempted_messages;
	cout<<"Number of successful messages: " <<c.get_success()<<endl;
	cout<<"Number of attempted messages: "<<attempted_messages<<endl;
	cout<<"Percent of successful messages: "<<c.get_success()/m<<"%"<<endl<<endl;
	cout<<"Successful messages for Station One: "<<success_one<<endl;
	cout<<"Successful messages for Station Two: "<<success_two<<endl;
	cout<<"Successful messages for Station Three: "<<success_three<<endl<<endl;

	if(success_one != 0 && success_two !=0 && success_three!=0)
	{
		cout<<"Average latency for Station one: " <<latency_one / success_one<<endl;
		cout<<"Average latency for Station two: "<<latency_two / success_two<<endl;
		cout<<"Average latency for Station three: "<<latency_three /success_three<<endl;
	}
	system("pause");

	return 0;
}
void update_waiting(Station &s, int &wait)
{
	if(s.is_waiting())
	{
		wait--;
		if(wait ==0)
		{
			s.set_waiting_status(0);
			wait = -1;
		}
	}
}
void check_if_full(Carrier &c, int &c1,int &c2,int &c3,Station &s0, Station &s1)
{
	if(c.is_full())
	{
		c.clear_carrier();
		c1=c2=c3=0;


		s1.set_collision(0);
		s0.set_collision(0);
	}
}
void check_for_collision(Carrier &c,int &count,int message,Station &s, int i, int &collision)
{
	if(s.is_in_collision() && !c.is_full())
	{
		c.add_bit(i,count,message);
		count++;
	}
}
void double_check(Station &s, int &collision, Carrier &c)
{
	if(s.its_transmitting() && !s.is_in_collision() && c.is_full())
	{
		s.set_collision(1);
		collision = s.get_r4();
	}
}
