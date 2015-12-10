//HashTable, specification
//Week 13
//Spring 2014

#include <iostream>
#include <cassert>

using namespace std;

class HashTable {
    
private:
    struct Node {
        int value;
        Node *next;
    };
    Node * table[100];
    int hash(int);
    
public:
    HashTable();    
    
 	void insert(int);

    void display();
    
    bool find(int);
    
};

