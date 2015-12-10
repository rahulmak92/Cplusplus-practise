// IntList header file
// Lab 8
// Fall 2014

class IntList {
private:
    struct Node {
        int value;
        Node* next;
    };
    
    Node* head;       // ptr to first element
    Node* cursor;     // ptr to current element
public:
    IntList();
    void insert(int);
    void advance();
    bool isEmpty();
    bool atEOL();
    int getCurrent();
    void resetFront();
    void resetLast();
    void remove();
    void destroy();
    ~IntList();
    
};
