#include "IntStack.h"
IntStack::IntStack()
{
 IntList();
}
void IntStack::push(int val)
{
        if(!isFull())
        {
                stack.insert(val);
        }
        else
        {
                cout<<" I dont know how it will "
                        <<"get full!";
        }
}
int IntStack::pop()
{
        if(!isEmpty())
        {
                int result;
                result=stack.getCurrent();
                stack.remove();
                stack.resetLast();
                return result;
        }
        else
        {
                cout<<"\n There is nothing to pop!";
                //return 0;
        }
}
bool IntStack::isEmpty()
{
        return stack.isEmpty();
}
bool IntStack::isFull()
{
        return false;
}
