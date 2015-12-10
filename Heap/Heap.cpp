//Heap, implementation
//Week 12
//Fall 2014

#include "Heap.h"

#include <algorithm>
#include <cmath>
using namespace std;

Heap::Heap() {
    size = 0;
}

bool Heap::isEmpty() {

    return size==0;
}

void Heap::insertItem(string x) {

    // place x at end of tree, use percolate up to move to proper place
    array[size+1] = x;
    size++;
    percolateUp(size);

}

void Heap::percolateUp(int loc) {

    if (loc < 2)
        return;
    // if array[loc] is greater than its parent: done
    if (array[loc] > array[loc/2])
        return;
    // else swap array[loc] with parent, repeat on the parent
    // Make this recursive.
    swap(array[loc], array[loc/2]);
    percolateUp(loc/2);

}

string Heap::deleteItem() {
    assert(size>0);

    // save top element in a var
    string value = array[1];
    // move last item to top, use percolate down to move it to proper place
    array[1] = array[size];
    size--;
    percolateDown(1);
    return value;
}


void Heap::percolateDown(int loc) {
    int left =  2*loc; //calculate index of left child
    int right = 2*loc+1;//calculate index of right child

    if (left>size)
        return;  // no children

    if (left==size) { //one child
        // compare array[loc] to array[left], swap if needed
        if (array[loc] > array[left])
            swap(array[loc],array[left]);
        //done
        return;
    }

    //two children:

    // if both children are greater than the parent: done
    if (array[left] > array[loc] && array[right]>array[loc])
        return;
    // otherwise, swap the smaller of the two children with the
    // parent, repeat
    if (array[left] < array[right]) {
        swap(array[left],array[loc]);
        percolateDown(left);
    }
    else {
        swap(array[right],array[loc]);
        percolateDown(right);
    }
}


void Heap::postOrderTraversal(int loc) {
    if (loc <= size) {
       postOrderTraversal(2*loc);
       postOrderTraversal(2*loc+1);
       cout << array[loc] << " ";
    }
}


// Provided:
void Heap::display () {
    for (int i=1; i<=size; i++) {
        if ((i & (i - 1)) == 0)  // i is a power of 2
            cout << endl;
        cout << array[i] << " " ;
    }
    cout << endl;
}
