//CharSet, specification
//Week 13
//Spring 2014

#include <iostream>
#include <cassert>

using namespace std;

class CharSet {
    
private:
    bool array[26];
    int map(char);
    
public:
    CharSet();
 	void insert(char);
    void display();
    bool find(char);
    
};

