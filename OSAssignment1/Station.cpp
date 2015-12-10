#include "Station.h"
#include<iostream>
#include<time.h>
#include<cstdlib>
using namespace std;

Station::Station()
{
	srand(time(NULL));
	max = 1;
	min = 0;
	transmitting = false;
	is_in_wait = false;
	in_collision = false;
}
Station::Station(int maximum, int minimum)
{
	srand(time(NULL));
}
double Station::get_r1()
{
	double number = (double)rand() / RAND_MAX;
	return number*(1- 0);
}
int Station::get_r2()
{
	return rand()%3+1;
}
int Station::get_r3()
{
	return rand()%15 +2;
}
int Station::get_r4()
{
	return rand()%24+1;
}
int Station::get_r5()
{
	return rand()%4 + 9;
}


