#include<iostream>
#include<cstring>
using namespace std;
#ifndef STUDENT_H
#define STUDENT_H
class student
{
	private:
			int id;
			string name;
			double gpa;
			string major;
	public:
			student()
			{
				id=0;
				gpa=0;
				name="";
				major="";
			}
			int getID()
			{
				return id;
			}
			void setID(int set_id)
			{
				id=set_id;
			}
			void addStudent(int,string,double,string);
			void display();
};
#endif
