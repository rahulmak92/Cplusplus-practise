#include "CSStudent.h"
#include<iostream>
using namespace std;
int main()
{
	CSStudent student("Jennifer Haynes","167W98337",2006);
	student.setMathHours(12);
	student.setCSHours(20);
	student.setGenEdHours(40);

	cout<<"The student "<<student.getName()
		<<" needs to take "<<student.getRemainingHours()
		<<" more hours to graduate.\n";
	return 0;
}
