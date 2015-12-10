#include "FinalExam.h"
#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	int questions,missed;
	cout<<"How many questions in final exam? :";
	cin>>questions;
	cout<<"How many questions did student miss?";
	cin>>missed;
	FinalExam test(questions,missed);
	cout<<setprecision(2);
	cout<<"\nEach question counts :"<<test.getPointsEach()
		<<" points"<<endl;
	cout<<"the exam score is :"<< test.getScore()<<endl;
	cout<<"the exam grade is :"<< test.getLetterGrade()<<endl;
	return 0;
}
