#include <iostream>
#include <iomanip>

using namespace std;


void stars(int n)
{
    if(n>0)
    {
        cout <<"*";
        stars(n-1);
    }
}

void rightTriangle(int n)
{
    if(n>0)
    {
        rightTriangle(n-1);
        cout << endl;
        stars(n);
    }
}
void squareRec(int n1, int n2)
{
    if(n1>0)
    {
        squareRec(n1-1, n2);
        cout << endl;
        stars(n2);
    }
}

void square(int n)
{
    squareRec(n, n);
}

void spaces(int n)
{
    if(n>0)
    {
        cout <<"_";
        spaces(n-1);
    }
}
void rightTriangleforspace(int n)
{
    if(n>0)
    {
        rightTriangleforspace(n-1);
        cout << endl;
        spaces(n);
    }
}
void pyramid(int n)
{
	rightTriangleforspace(n);
}


int main()
{
    //rightTriangle(5);

    //square(5);
    pyramid(5);
    return 0;
}
