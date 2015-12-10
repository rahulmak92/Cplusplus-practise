#include "LinkedList.h"
using namespace std;
int main()
{
	LinkedList l1;
	l1.addNode(2);
	l1.addNode(3);
	l1.addNode(3);
	l1.addNode(3);
	l1.addNode(4);
	l1.addNode(4);
	l1.addNode(4);
	l1.addNode(4);
	l1.addNode(4);
	l1.addNode(4);
	l1.addNode(6);
	l1.addNode(6);
	l1.addNode(6);
	l1.addNode(7);
	l1.addNode(7);	l1.addNode(7);	l1.addNode(7);
	l1.addNode(7);	l1.addNode(7);	l1.addNode(7);

	l1.displayList();
	cout<<endl<<"Deletion"<<endl;
	l1.deleteNode(3);
	l1.deleteNode(6);
	cout<<endl;
	l1.displayList();

	l1.findMode();
	return 0;
}
