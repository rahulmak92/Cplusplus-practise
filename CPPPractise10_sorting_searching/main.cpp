#include "student.h"
#include<iostream>
using namespace std;
template<class T>
void bubbleSort (T a[], int size) {

    int count = 0;
    bool swapped;
    do
    {
        swapped = false;
        for (int i = 0; i < (size-1); i++)
        {
            count++;
            if (a[i].getID() > a[i+1].getID())
            {
                swap(a[i],a[i+1]);
                swapped = true;
            }
        }
    } while (swapped);
    cout << "Bubble sort: " << count << endl;
}

int main()
{
	student s1[4];
	int id;
	string name,major;
	double gpa;

	for(int i=0;i<4;i++)
	{
		cout<<"enter student id: ";
		cin>>id;
		cout<<"enter name: ";
		cin>>name;
		cout<<"Enter major: ";
		cin>>major;
		cout<<"Enter gpa: ";
		cin>>gpa;
		s1[i].addStudent(id,name,gpa,major);
	}
	for(int i=0;i<4;i++)
	{
		cout<<"---------------------"<<endl;
		cout<<"Student "<<i+1<<endl;
		s1[i].display();
	}
	bubbleSort(s1,4);
	for(int i=0;i<4;i++)
	{
		cout<<"---------------------"<<endl;
		cout<<"Student "<<i+1<<endl;
		s1[i].display();
	}

	return 0;
}
