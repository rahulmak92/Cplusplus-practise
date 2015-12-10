//IntStack implemenation file
//Lab 9
//Fall 2014

#include "IntStack.h"
#include <cassert>
using namespace std;

IntStack::IntStack() {
    
}
//Note: I am putting top at the end of the list, so I make sure cursor points
//      to the last element AFTER pop and push.
void IntStack::push(int num) {
    assert (!isFull());

    stack.insert(num);
    //cursor now points to num, the last element
}
int IntStack::pop() {
    assert (!isEmpty());
    
    int result = stack.getCurrent();
    stack.remove();
    //after the remove, cursor points to EOL, so I reset it to last elem:
    stack.resetLast();
    return result;
}
bool IntStack::isEmpty() {
    return stack.isEmpty();
}
bool IntStack::isFull() {
    return false;
}

