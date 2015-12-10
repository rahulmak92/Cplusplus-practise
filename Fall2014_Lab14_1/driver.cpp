#include<iostream>
using namespace std;
void triangle(int);
int main()
{
        int n;
        cout<<"Enter N:";
        cin>>n;
        triangle(n);
        return 0;
}
void triangle(int n)
{
        int k = 0;
        for(int i = 1; i <= n; i++)
        {
                for(int j = 1; j <=(n-i); j++)
                {
                        cout<<" ";
                }
                while(k != 2*i-1 && k<i)
                {
                        cout<<"* ";
                        k++;
                }
                k = 0;
        cout<<endl;
        }
}
