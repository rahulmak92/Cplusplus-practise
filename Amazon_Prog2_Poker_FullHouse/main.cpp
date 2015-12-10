//
//  main.cpp
//  Amazon_Practise2
//
//  Created by Rahul Makwana on 3/7/15.
//  Copyright (c) 2015 Rahul Makwana. All rights reserved.
//problem :
//An optimal algorithm to check whether a hand of cards was a full house (in Poker) or not.
//

#include <stdio.h>
#include <iostream>
bool isFlush(char []);
using namespace std;
int main()
{
    char *hand;
    hand = new char[5];
    cout<<"Input hand :";
    for(int i=0;i<5;i++)
    {
        cin>>hand[i];
    }
    for(int i=0;i<5;i++)
    {
    	cout<<hand[i]<<";";
    }
    if(isFlush(hand))
    {
        cout<<"Congrats! It's Full house!";
    }
    else
    {
        cout<<"No Full house!";
    }
    return 0;
}
bool isFlush(char hands[])
{
    return true;
}
