#ifndef INTLIST_H
#define INTLIST_H
#include <iostream>
using namespace std;
class IntList {
private:
    struct Node {
        int value;
        Node* next;
    };
    Node* head;       // ptr to first element
    int countOddNodes(Node *,int );
public:
    IntList();
    ~IntList();
    void appendNode(int);
    int countOddNodes()
    {
    	return countOddNodes(head,0);
    }
};
#endif
