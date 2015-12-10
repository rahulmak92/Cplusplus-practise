#include "IntQueue.h"
#include <iostream>
using namespace std;
int main()
{
	const int MAX_VALUES=5;
	IntQueue iQueue(MAX_VALUES);
	for(int x=0;x<MAX_VALUES;x++)
	{
		iQueue.enqueue(x);
	}
	iQueue.enqueue(MAX_VALUES);

	cout<<"Values in Queue were :"<<endl;
//need to implement a display Queue function

	//IntQueue queue2(5);
	//queue2(iQueue);
	//queue2.
	return 0;
}
