/*
 * From: Jill Seaman [mailto:js236@txstate.edu]
Sent: Wednesday, February 25, 2015 1:24 PM
Subject: Spr15.CS5301.251: Week 6: another practice problem

Hello-
A student asked for a more challenging operator overloading problem.  Also I see now that some of the problems from the book are not described well.  So you need a better problem.  So here it is:
Implement a class to represent a Set of numbers (integers).
Use an array to represent the set but do not allow duplicates.
Implement insert (to add an element) and member (returns true if x is an element).
Overload + to be the union of two sets.
Overload * to be the intersection of 2 sets.
Overload - to be the difference/subtraction of 2 sets.
Overload == to be true if both sets contain the same elements.
Thanks-
Dr. Seaman
 */
#include<iostream>
#include "SetOfIntegers.h"
using namespace std;
int main()
{
 Set s1(4);
 Set s2(3);
 Set s4(5);
 s1.insert(4);
 s1.insert(3);
 s1.insert(7);
 s1.insert(4);
 s1.displaySet();
 s2.insert(3);
 s2.insert(9);
 s2.insert(10);
 s2.displaySet();
 Set s3=s1;
 s1=s1+s2;
 cout<<endl;
 cout<<"----------------"<<endl;
 cout<<"After Union :"<<endl;
 s1.displaySet();
 cout<<"----------------"<<endl;
 cout<<"After Intersection of :"<<endl;
 s1.displaySet(); cout<< " \t and "; s2.displaySet();
 cout<<"=>";
 //s1=s1*s2;
 //s1.displaySet();
 //s2.displaySet();
 cout<<"----------------"<<endl;
 cout<<"After Subtraction of :"<<endl;
 s2.displaySet();cout<< " \t and "; s1.displaySet();
 s4=s1-s2;
 s4.displaySet();

 return 0;
}
