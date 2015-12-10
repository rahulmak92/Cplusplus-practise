#include "student.h"

void student::addStudent(int stu_id,string stu_name,double stu_gpa,string stu_major)
{
	id=stu_id;
	name=stu_name;
	gpa=stu_gpa;
	major=stu_major;
}
void student::display()
{
	cout<<"Student ID: "<<id<<endl;
	cout<<"Student name: "<<name<<endl;
	cout<<"Student major: "<<major<<endl;
	cout<<"Student gpa: "<<gpa<<endl;
}
