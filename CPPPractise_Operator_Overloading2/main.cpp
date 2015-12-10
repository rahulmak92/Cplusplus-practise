#include <iostream>
#include "Rectangle.h"
using namespace std;
int main()
{
	Rectangle box1(10.0,10.0);
	Rectangle box2(20.0,20.0);

	cout<<"box1's width and length: "<<box1.getWidth()
		<<" "<<box1.getLength()<<endl;
	cout<<"box2's width and length: "<<box2.getWidth()
			<<" "<<box2.getLength()<<endl;
	box2=box1;
	cout<<"box1's width and length: "<<box1.getWidth()
		<<" "<<box1.getLength()<<endl;
	cout<<"box2's width and length: "<<box2.getWidth()
			<<" "<<box2.getLength()<<endl;

	return 0;
}
