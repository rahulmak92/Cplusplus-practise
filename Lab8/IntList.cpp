// IntList implementation file
// Lab 8
// Fall 2014

#include <cstdlib>
#include <iostream>
using namespace std;

#include "IntList.h"

IntList::IntList() {
    head = NULL;
    cursor = NULL;
}

void IntList::insert(int x) {
    // set up the new node:
    Node *p = new Node();
    p->value = x;
    
    // if the cursor points to a node, insert after.
    // be careful, don't do the assignments out of order
    if (cursor) {
        p->next = cursor->next;
        cursor->next = p;
        cursor = p;
    } else {
        // insert befor the first element
        p->next = head;
        head = p;
        cursor = p;
    }
}

void IntList::advance() {
    //Note: if cursor is pointing to the last element, and I call advance()
    //   then the cursor should become NULL.
    // Don't access cursor->next if cursor is NULL!
    if (cursor)
        cursor = cursor -> next;
}

bool IntList::isEmpty() {
    return (head==NULL);
}

bool IntList::atEOL() {
    // EOL is "End of List", which is true when the cursor is NULL
    // (when it has advanced BEYOND the last node).
    return (cursor == NULL);
}

int IntList::getCurrent() {
    // Don't access cursor->value if cursor is NULL!
    if (cursor)
        return cursor->value;
    else
        return 0;
}

void IntList::resetFront() {
    cursor = head;
}

void IntList::resetLast() {
    resetFront();
    if (cursor)
      while (cursor->next) {
        cursor = cursor->next;
      }
}


void IntList::remove() {
    // make sure cursor points to something
    if (cursor==NULL)
        return;
    
    if (cursor == head) {
        //remove first item
        head = cursor->next;
        delete cursor;
        cursor = head;
    }
    else {
        //find predecessor to cursor
        Node *p = head;
        while (p->next!=cursor)
            p = p->next;
        //now remove node at cursor
        p->next = cursor->next;
        delete cursor;
        cursor = p->next;
    }
}

void IntList::destroy() {
    resetFront();
    while (!isEmpty()) {
        remove();
    }
    //head and cursor will now be NULL, via remove()
}

IntList::~IntList() {
    destroy();
}
