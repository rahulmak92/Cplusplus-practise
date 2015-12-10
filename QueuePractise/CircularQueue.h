#ifndef CIRCULARQUEUE_H
#define CIRCULARQUEUE_H
#include <iostream>
using namespace std;
class CircularQueue
{
	private:
			struct Node
			{
				int data;
				Node *next;
			};
			Node *front;
			Node *rear;
			void insertAt(Node*,int,int);
	public:
				CircularQueue()
				{
					front=rear=NULL;
				}
				void enqueue(int);
				int dequeue();
				void printQ();
				void insertAt(int index,int val)
				{
					insertAt(front,index,val);
				}
};
#endif
