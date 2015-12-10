//Driver file for Stack
//Lab 9
//Fall 2014

#include <iostream>
using namespace std;

#include "IntStack.h"


int main() {
    IntStack s;
    
    s.push(2);
    s.push(7);
    s.push(12);

    int x = s.pop();
    int y = s.pop();
    s.push(10);
    int z = s.pop();
    
    cout << x << " " << y << " " << z << endl;
    s.pop();
    if (s.isEmpty())
        cout << "empty" << endl;
    else
        cout << "not empty" << endl;

    if (s.isFull())
        cout << "full" << endl;
    else
        cout << "not full" << endl;
    

}