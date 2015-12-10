#ifndef INTLIST_h
#define INTLIST_H
//Header file
//Lab 8
//Fall 2014


class IntList
{
	private:
    		struct Node
    		{
    			int value;
    			Node* next;
    		};
    		Node* head;       // ptr to first element
    		Node* cursor;     // ptr to current element
	public:
    	    IntList();
    	    void insert(int); //insert after cursor, cursor points to new elem
    	                      //if EOL, inserts at front
    	    void advance();
    	    bool isEmpty();
    	    bool atEOL();
    	    int getCurrent();
    	    void resetFront();
    	    void resetLast();
    	    void remove(); // remove element at cursor, cursor points to next elem
    	    void destroy();
    	    ~IntList();
};

#endif
