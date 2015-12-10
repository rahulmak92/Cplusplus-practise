//Heap, specification
//Week 12
//Fall 2014

#include <iostream>
#include <cassert>

using namespace std;

class Heap {

private:
    string array[100]; // nodes are stored in an array (start at 1)
    int size;          // number of nodes in the array

    //private functions
    // Given a position in the array, percolate that element up into place
    void percolateUp(int);
    // Given a position in the array, percolate that element down into place
    void percolateDown(int);
    void postOrderTraversal(int);


public:
    Heap();

    //Adds an item, use percolateUp to put in the proper place
    void insertItem(string);

    //Removes item at top of tree (root), replace with last item
    //use percolateDown to put it in its proper place
    string deleteItem();

    // displays the tree like this (positions in array are shown):
    // 1
    // 2 3
    // 4 5 6 7
    // 8 9 10 11 12 13 14 15
    // etc.
    void display();

    // output the items using postorder traversal
    void postOrderTraversal() { postOrderTraversal(1); }

    // Returns true if the Heap is empty
    bool isEmpty();

};
