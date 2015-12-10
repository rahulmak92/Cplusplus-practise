#include "DynIntQueue.h"
#include <iostream>
using namespace std;
int main()
{
	DynIntQueue iQ;
	for(int i=0;i<5;i++)
	{
		iQ.enqueue(i);
	}
	while(!iQ.isEmpty())
	{
		int value;
		iQ.dequeue(value);
		cout<<value<<"\t";
	}
	return 0;
}
