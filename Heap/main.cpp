//Heap, driver
//Week 12
//Fall 2014

#include <iostream>
using namespace std;

#include "Heap.h"



int main() {

    Heap h1;
    h1.insertItem("2");
    h1.insertItem("8");
    h1.insertItem("6");
    h1.insertItem("1");
    h1.insertItem("ten");
    h1.insertItem("3");
    h1.insertItem("eleven");
    h1.insertItem("4");

    h1.display();

    cout << "deleted " << h1.deleteItem() << endl ;
    h1.display();
    cout << "deleted " << h1.deleteItem() << endl ;
    h1.display();

    if (h1.isEmpty())
        cout << "Heap is empty" << endl;
    else
        cout << "Heap is NOT empty" << endl;

    h1.postOrderTraversal();

}
