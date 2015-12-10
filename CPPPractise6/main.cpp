#include "Cube.h"
#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	double cubeWidth,cubeLength,cubeHeight;
	cout<<"Enter the dimensions of a cube: \n";
	cout<<" Width =";
	cin>>cubeWidth;
	cout<<" Length =";
	cin>>cubeLength;
	cout<<" Height =";
	cin>>cubeHeight;
	Cube myCube(cubeWidth,cubeLength,cubeHeight);
	cout<<"Here are the cube's properties:\n";
	cout<<setprecision(2)<<fixed;
	cout<<"Width :"<<myCube.getWidth()<<endl;
	cout<<"Length :"<<myCube.getLength()<<endl;
	cout<<"Height :"<<myCube.getHeight()<<endl;
	cout<<"Base Area :"<<myCube.getArea()<<endl;
	cout<<"Volume :"<<myCube.getVolume()<<endl;
return 0;
}
