// Quiz 8
// Fall 2014
#include <iostream>
using namespace std;

//From the quiz instructions:
class IntList {
private:
    struct Node {
        int value;
        Node* next;
    };
    
    Node* head;       // ptr to first element
    Node* cursor;     // ptr to current element
public:
    IntList() { head = cursor = NULL; }
    void insert (int);   // already defined (see lab solution)
    void resetFront();   // already defined (see lab solution)
    void moveToEnd();
};

// Solution is: the following  function:
void IntList::moveToEnd() {
    
    // Exactly like remove, but do not delete cursor or change cursor
    if (head == cursor) {
        head = head->next;
    } else {
        //find the previous node
        Node *p = head;
        while (p->next != cursor)
            p = p->next;
        
        p->next = cursor->next; // remove element
    }
    
    // Exactly like append, but cursor is already pointing to the "new" node
    if (head == NULL)
        head = cursor;
    else {
        //find the last node
        Node *p = head;
        while (p->next != NULL)
            p = p->next;
        p->next = cursor;
    }
    
    // set cursor->next to NULL, it will be the new last element
    cursor->next = NULL;
}


// not part of the quiz, just to test:
void showList(IntList &list) {
    list.resetFront();
    while (!list.atEOL()) {
        cout << list.getCurrent() << " ";
        list.advance();
    }
    cout << endl;
}

int main () {
    
    IntList list;
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.resetFront();
    list.moveToEnd();
    showList(list);
    
}