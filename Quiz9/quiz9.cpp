// Quiz 9
// Fall 2014

#include <iostream>
#include <cassert>
using namespace std;
//From the quiz instructions:
class Stack {
private:
    struct Node {
        double value;
        Node* next;
    };
    Node* top;       // ptr to first element
public:
    Stack() {top = NULL;}
    void push(double);
    double pop();   //define this
    bool isEmpty();
    bool isFull();
    ~Stack();
};
class Queue {
private:
    double arr[5];
    int front, rear, numItems;
public:
    Queue() {front = numItems = 0; rear = -1;}
    void enqueue(double);   //define this
    double dequeue();
    bool isEmpty();
    bool isFull();
};

// Solution is: the following two functions:
double Stack::pop() {
    assert(!isEmpty());
    
    int result = top->value;
    Node * temp = top;
    top = top->next;
    delete temp;
    return result;    
}

void Queue::enqueue(double x) {
    assert(!isFull());   //should make sure it's not full first
    
    rear = (rear+1) % 5; //wrap the index around
    arr[rear] = x;
    numItems++;
    
}
