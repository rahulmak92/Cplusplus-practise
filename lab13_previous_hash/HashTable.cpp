//HashTable, implementation
//Week 13
//Spring 2014
//arrays-for
//ppointers-while

#include "HashTable.h"

#include <iostream>
using namespace std;

HashTable::HashTable() {
    for (int i=0; i<100; i++)
        table[i] = NULL;
}

int HashTable::hash (int x) {
    return x % 100;
}

void HashTable::insert (int x) {
    
    // optional, do not add x if it's already in the table.
    if (find(x))
        return;
    
    Node *newNode = new Node;
    newNode->value = x;

    // this inserts at the front of the list.
    // appending to the end of the list is also fine.
    int pos = hash(x);
    if (table[pos] == NULL) {
        table[pos] = newNode;
        newNode->next = NULL;
    } else {
        Node *p = table[pos];
        table[pos] = newNode;
        newNode->next = p;
    }
}

void HashTable::display() {
    for (int i=0; i<100; i++)
        if (table[i]) {
            cout << i << ": ";
            Node *p = table[i];
            while (p) {
                cout << p->value << " ";
                p = p->next;
            }
            cout << endl;
        }
}

bool HashTable::find(int x) {
    int pos = hash(x);
    if (table[pos]) {
        Node *p = table[pos];
        while (p && p->value!=x) {
            p=p->next;
        }
        return(p!=NULL);
    } else
        return false;
}

