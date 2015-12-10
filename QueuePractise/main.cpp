#include "CircularQueue.h"
using namespace std;
int main()
{
	CircularQueue q1;
	q1.enqueue(2);
	q1.enqueue(9);
	q1.enqueue(10);
	q1.enqueue(1);
	q1.insertAt(7,6);

	q1.printQ();
	return 0;
}
