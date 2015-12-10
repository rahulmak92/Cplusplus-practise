#include<iostream>
using namespace std;
class Animal
{
	public:
			Animal()
			{
				cout<<"Animal constructor executing. \n";
			}
			virtual ~Animal()
			{
				cout<<"Animal Destructor executing.\n";
			}
};

class Dog: public Animal
{
	public:
			Dog():Animal()
			{
				cout<<"dog contructor \n";
			}
			~Dog()
			{
				cout<<"dog Destructor\n";
			}
};
int main()
{
	Animal *myAnimal = new Dog;

	delete myAnimal;
	return 0;
}
