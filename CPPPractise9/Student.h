#ifndef STUDENT_H
#define STUDENT_H
#include<string>
using namespace std;
class Student
{
	protected:
				string name;
				string idNumber;
				int yearAdmitted;
	public:
				Student()
				{
					name="";
					idNumber="";
					yearAdmitted=0;
				}
				Student(string n,string id,int year)
				{
					set(n,id,year);
				}
				void set(string n,string id,int year)
				{
					name=n;
					idNumber=id;
					yearAdmitted=year;
				}
				const string getName() const
				{
					return name;
				}
				const string getIdNum() const
				{
					return idNumber;
				}
				int getYearAdmitted() const
				{
					return yearAdmitted;
				}
				virtual int getRemainingHours() const=0;
};
#endif
