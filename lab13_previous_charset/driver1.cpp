//CharSet, driver
//Week 13
//Spring 2014

#include "CharSet.h"

#include <iostream>
using namespace std;

int main() {
    CharSet s;
    
    s.insert('A');
    s.insert('P');
    s.insert('P');
    s.insert('L');
    s.insert('E');
    
    s.display();
    
    if (s.find('P'))
        cout << "P is in the set" << endl;
    else
        cout << "P is NOT in the set" << endl;
    if (s.find('X'))
        cout << "X is in the set" << endl;
    else
        cout << "X is NOT in the set" << endl;
}