#include "MathStack.h"

void MathStack :: add()
{
	int num,sum;
	pop(sum);
	pop(num);
	sum+=num;
	push(sum);
}
void MathStack:: sub()
{
	int num,diff;
	pop(diff);
	pop(num);
	diff-=num;
	push(diff);
}
