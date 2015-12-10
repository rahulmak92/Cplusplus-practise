#ifndef INTQUEUE_H
#define INTQUEUE_H
class IntQueue
{
	private:
			int *queueArray;
			int queueSize;
			int front;
			int rear;
			int numOfItems;
	public:
			IntQueue(int);
			//copy constructor
			IntQueue(const IntQueue&);
			~IntQueue();
			void enqueue(int);
			void dequeue(int &);
			bool isEmpty() const;
			bool isFull() const;
			void clear();
};
#endif
