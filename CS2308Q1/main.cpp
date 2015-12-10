#include<iostream>
using namespace std;
template<class T1,class T2>
int largest(const T1 &var1,T2 &var2)
{
	if(sizeof(var1) > sizeof(var2))
		return sizeof(var1);
	else
		return sizeof(var2);
}
int main()
{
	int i=0;
	char c= ' ';
	float f=0.0;
	double d=0.0;

	cout<<largest(i,d)<<endl;
	cout<<largest(c,f)<<endl;
	return 0;
}
