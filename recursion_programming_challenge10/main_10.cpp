#include "NumberList.h"
#include<iostream>
using namespace std;
int main()
{
	NumberList obj1;
	obj1.insertNode(23);
	obj1.insertNode(2);
	obj1.insertNode(10);
	obj1.insertNode(90);
	cout<<"We have :\n";
	obj1.displayList();
	cout<<"\nthis looks like largest one "
		<<obj1.maxNodeFinder();
	return 0;
}
