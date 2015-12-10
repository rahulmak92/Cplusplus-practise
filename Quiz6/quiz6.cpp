// Quiz 6
// Fall 2014

#include <iostream>
#include <cassert>
using namespace std;


class SimpleVector {
private:
    int *aptr;        // To point to the allocated array
    int arraySize;    // Number of elements in the array
    
public:
    SimpleVector()    { aptr = 0; arraySize = 0;}
    
    // Copy constructor, destructor
    SimpleVector(const SimpleVector &);  //assume this is defined
    ~SimpleVector();                     //assume this is defined
    
    int size() const  { return arraySize; }
    int getElementAt(int position);      //assume this is defined
    
    void push_back(int);  // adds new element to end of vector, already defined
    int pop_back();       // removes last element from vector, already defined
    
    SimpleVector operator+ (SimpleVector);
    bool operator== (SimpleVector);
    bool operator< (SimpleVector);
    
};

SimpleVector SimpleVector::operator+ (SimpleVector that) {
    SimpleVector result;
    for (int i=0; i<arraySize; i++)
        result.push_back(getElementAt(i));
    for (int i=0; i<that.arraySize; i++)
        result.push_back(that.getElementAt(i));
    return result;
}

bool SimpleVector::operator== (SimpleVector that) {
    if (arraySize != that.arraySize)
        return false;
    for (int i=0; i<arraySize; i++)
        if (getElementAt(i) != that.getElementAt(i))
            return false;
    return true;
}

int main()
{
    SimpleVector v1, v2;
    v1.push_back(1);
    v1.push_back(2);
    v2.push_back(3);
    
    if (v1==v2)
        cout << "they are equal" << endl;
    else
        cout << "they are not equal" << endl;
    
    SimpleVector v3 = v1+v2;
    for (int i=0; i<v3.size(); i++)
        cout << v3.getElementAt(i) << " ";
    cout << endl;
}




