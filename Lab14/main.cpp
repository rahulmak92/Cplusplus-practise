
#include <iostream>
#include "IntList.h"
using namespace std;
int main()
{
	IntList l1;
	l1.appendNode(4);
	l1.appendNode(3);
	l1.appendNode(8);
	l1.appendNode(9);
	l1.appendNode(1);
	l1.appendNode(3);
	cout<<"count is : "<<l1.countOddNodes()<<endl;
	return 0;
}
