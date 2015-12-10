#include<iostream>
#include "NumberList.h"
using namespace std;
int main()
{
	const int MAX=10;
	NumberList list;
	for(int x=0;x<MAX;x++)
	{
		list.insertNode(x);
	}
	cout<<"the number of nodes in the list :"
		<<list.numNodes()<<endl;
	list.displayList();
	cout<<"\nBackwards : \n";
	list.displayBackwards();
	cout<<endl<<list.countsum();
	return 0;
}
