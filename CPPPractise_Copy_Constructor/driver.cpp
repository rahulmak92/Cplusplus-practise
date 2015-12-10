#include <iostream>
#include "StudentTestScores.h"
using namespace std;
void displayStudent(StudentTestScores);
int main()
{
	StudentTestScores student1("Kelly Thorton",3);
	student1.setTestScore(100.0,0);
	student1.setTestScore(95.0,1);
	student1.setTestScore(80,2);

	StudentTestScores student2("Jimmy Griffin",5);
	student2.setTestScore(101.0,0);
	student2.setTestScore(91.0,1);
	student2.setTestScore(89,2);
	student2.setTestScore(101.0,3);
	student2.setTestScore(91.0,4);

	displayStudent(student1);
	displayStudent(student2);

	cout<<"-------------------------"<<endl;
	cout<<"After copying :"<<endl;
	cout<<"-------------------------"<<endl;
	student2=student1;
	displayStudent(student1);
	displayStudent(student2);

	return 0;
}
void displayStudent(StudentTestScores st)
{
	cout<<"Name :"<<st.getStudentName()<<endl;
	cout<<"Test Scores: ";
	for(int i=0;i<st.getNumTestScores();i++)
	{
		cout<<st.getTestScore(i)<<" ";
	}
	cout<<endl;
}
