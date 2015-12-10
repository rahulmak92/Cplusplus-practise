//HashTable, driver
//Week 13
//Spring 2014

#include "HashTable.h"

#include <iostream>
using namespace std;

int main() {
    HashTable s;
    
    s.insert(111);
    s.insert(222);
    s.insert(999);
    s.insert(299);
    s.insert(333);
    s.insert(333);
    s.insert(211);
    s.display();
    
    if (s.find(299))
        cout << "299 is in the set" << endl;
    else
        cout << "299 is NOT in the set" << endl;
    if (s.find(300))
        cout << "300 is in the set" << endl;
    else
        cout << "300 is NOT in the set" << endl;
}
