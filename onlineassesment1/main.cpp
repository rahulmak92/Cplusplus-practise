#include <iostream>
using namespace std;
void printfibo(int digit)
{
	int x = 0;
	int y = 1;
	for(int loop = 0; loop < digit ; loop++)
	{
		int z;

	if(loop<=1 & x>0)
	{
		z=loop;
		cout<<z<<" ";

	}
	else
	{
		z = x+y;
		x=y;
		y=z;
		cout<<z<<" ";

	}
	}

}
int main()
{
	printfibo(7);
	return 0;
}
