//CharSet, implementation
//Week 13
//Spring 2014

#include "CharSet.h"

#include <iostream>
using namespace std;

CharSet::CharSet()
{
    for (int i=0; i<26; i++)
    {
    	array[i] = false;
    }
}

int CharSet::map (char x)
{
    return (x-'A');
}

void CharSet::insert (char x)
{
    int pos = map(x);
    if (pos >=0 && pos < 26)
        array[pos] = true;
}

void CharSet::display()
{
    for (int i=0; i<26; i++)
    {
    	if (array[i])
        {
    		cout << char('A'+i) << " " ;
        }
    }
    	cout << endl;
}

bool CharSet::find(char x)
{
    int pos = map(x);
    if (pos >=0 && pos < 26)
    {
    	return array[pos];
    }
    return false;
}
