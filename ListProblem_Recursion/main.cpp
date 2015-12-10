#include <iostream>
#include <iomanip>
#include "NumberList.h"

using namespace std;

int main()
{
	NumberList list;
	list.appendNode(1);
    list.appendNode(1.0);
	list.insertNode(8.2);
	list.insertNode(3.0);
	list.insertNode(4.0);
	list.insertNode(4.0);
	list.appendNode(1.5);
	list.appendNode(50.0);
	list.appendNode(2.6);
	list.appendNode(50);

/*	cout << "Member of The List are ::: \n";
	list.displayList();
	cout << endl;

	list.deleteNode(7.9);

	cout << "Member of The List are ::: \n";
	list.displayList();
	cout << endl;

	cout <<"***********" << endl;
	cout <<"Max Node :: " << list.maxNode() << endl;
	cout <<"Min Node :: " << list.minNode() << endl;

	cout <<"***********" << endl;
	if(list.isSorted())
		cout <<"isSorted :: Yes" << endl;
	else
		cout <<"isSorted ::  No " << endl;

	cout <<"***********" << endl;
	cout <<"totalSum :: " << list.totalSum()<< endl;

	cout <<"***********" << endl;
	list.reverseList();
	cout << endl;

	cout <<"***********" << endl;
	cout << "Node Having Value occurrence :: "<< list.nodeOccurrence(2.0) << endl;
*/
	list.sort();
	list.displayList();
	cout <<"***********" << endl;
	cout << "Removing duplicates elements :: " << endl;
	list.removeDuplicates();
/*
	cout << endl;
	list.displayList();

	cout <<"***********" << endl;
		cout << "Node Having Value occurrence :: "<< list.nodeOccurrence(4.0) << endl;

	cout  << list.count();
	*/


	cout << endl;
	list.displayList();
	return 0;

}
