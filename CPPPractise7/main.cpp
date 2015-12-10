#include<iostream>
#include<iomanip>
#include "PassFailExam.h"
using namespace std;
void displayGrade(const GradedActivity *);
int main()
{
	int questions,missed;
	double minPassing;

	cout<<"How manu questions are on the exam? :";
	cin>>questions;
	cout<<"How many questions did the student miss?:";
	cin>>missed;
	cout<<"Enter the minimum passing score for this test :";
	cin>>minPassing;

	PassFailExam exam(questions,missed,minPassing);
	GradedActivity grade;
	grade.setScore(75);
	cout<<fixed<<setprecision(1);
	cout<<"\nEach questions counts "
		<<exam.getPointsEach()<<" points.\n";
	cout<<"the minimum passign score is "
		<<exam.getMinPassingScore()<<endl;
	cout<<"the student's exam score is "
		<<exam.getScore()<<endl;
	cout<<"the student's grade is "
		<<exam.getLetterGrade()<<endl;

	cout<<"-----------------------------------------\n";
	cout<<"-----------------------------------------\n";
	cout<<grade.getLetterGrade();
	cout<<endl;
	displayGrade(&exam);

	return 0;
}
void displayGrade(const GradedActivity *activity)
{
	cout<<setprecision(1)<<fixed;
	cout<<"The activity's numeric score is "
		<<activity->getScore()<<endl;
	cout<<"the activity's letter grade is "
		<<activity->getLetterGrade()<<endl;
}
