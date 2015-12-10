#ifndef CSSTUDENT_H
#define CSSTUDENT_H
#include "Student.h"
const int MATH_HOURS = 20;
const int CS_HOURS = 40;
const int GEN_ED_HOURS = 60;
class CSStudent : public Student
{
	private:
			int mathHours;
			int csHours;
			int genEdHours;
	public:
				CSStudent():Student()
				{
					mathHours=0;
					csHours=0;
					genEdHours=0;
				}
				CSStudent(string n,string id,int year): Student(n,id,year)
				{
					mathHours=0;
					csHours=0;
					genEdHours=0;
				}
				void setMathHours(int mh)
				{
					mathHours=mh;
				}
				void setCSHours(int csh)
				{
					csHours=csh;
				}
				void setGenEdHours(int geh)
				{
					genEdHours=geh;
				}
				virtual int getRemainingHours() const;
};
#endif
