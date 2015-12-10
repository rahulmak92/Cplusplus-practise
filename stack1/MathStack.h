#ifndef MATHSTACK_H
#define MATHSTACK_H
#include"IntStack.h"
class MathStack:public IntStack
{
	public:
			MathStack(int s):IntStack(s)
			{

			}
			void add();
			void sub();
};
#endif
