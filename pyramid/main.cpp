#include<iostream>
using namespace std;
int main()
{
  int z=1;

  for (int i=0; i<5; i++)
  {
    for (int j=5; j>i; j--)
    {
      cout<<"_";
    }
    cout<<"*";   // displaying asterisk here

    if (i!=0)
    {
      for (int k=1; k<=z; k++)
      {
        cout<<"*";
      }
      cout<<"*";
      z+=2;
    }
    cout<<endl;  // endl is for new line
  }

//  for (int i=0; i<=z+1; i++)
//  {
//    cout<<"1";
//  }

return 0;
}
