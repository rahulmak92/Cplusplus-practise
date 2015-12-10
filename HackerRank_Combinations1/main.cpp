#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
    int no_of_inputs=0;
    int *count;
    int temp;
    int out=0;
    cin>>no_of_inputs;
    count = new int(no_of_inputs);
    for(int i=0;i<no_of_inputs;i++)
    {
        cin>>temp;
        count[i]=temp;
    }
    for(int i=0;i<no_of_inputs;i++)
    {
    	if(count[i]>2)
    	{
    		out=pow(2,count[i]);
    	}
    	else
    	{
    		if(count[i]==2)
    		{
    			out=1;
    		}
    		else
    			out=0;
    	}
    	cout<<out<<endl;
        //cout<<<<endl;
    }
    return 0;
}
