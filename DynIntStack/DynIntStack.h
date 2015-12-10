#ifndef DYNINTSTACK_H
#define DYNINTSTACK_H
class DynIntStack
{
	private:
			struct StackNode
			{
				int value;
				StackNode *next;
			};
			StackNode *top;
	public:
			DynIntStack();
			~DynIntStack();
			void push(int);
			void pop(int &);
			bool isEmpty();
			bool isFull();
};
#endif
