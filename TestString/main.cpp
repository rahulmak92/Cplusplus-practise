#include<iostream>
#include <map>
using namespace std;

int main()
{
	string t;
	t="778869879";
	int l=0;
	int arr[t.length()];
	while(l<=t.length())
	{
		arr[l]=t[l]-'0';
		l++;
	}
	int size=t.length();
	for(int i=0;i<size;i++)
	{
		int j=0;
		while(j<size)
		{
			if(j!=i && arr[j]==arr[i])
			{

			}
		}

	}
	return 0;
//    string word = "778869879";
//    map<char,int> charCount;
//    for (unsigned int i=0; i<word.size(); i++)
//        charCount[word[i]]++;
//
//    for (map<char, int>::iterator it = charCount.begin(); it != charCount.end(); ++it)
//        cout << it->first << ": " << it->second << endl;
//
//    return 0;

}
