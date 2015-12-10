#include <iostream>
using namespace std;
class Base1
{
  public:

  virtual int virt1()
  {
	  return 100;
  }

  int data1;
};

class Derived : public Base1
{
  public:

  virtual int virt1()
  {
	  return 150;
  }

  int derivedData;
};

int Global1( Base1 * b1 )
{
  return b1->virt1();
}

void main1()
{
  Derived * d = new Derived;

  cout<<"d->virt1() "<<d->virt1()<<endl;
  cout<<"Global(d) "<<Global1(d)<<endl;
  cout<<"size: Base1: "<<sizeof(Base1)<<endl;
  cout<<"size: Derived: "<<sizeof(Derived)<<endl;
}


class Base2
{
  public:

  virtual int virt2() { return 200; }

  int data2;
};

class MultipleDerived : public Base1, public Base2
{
  public:

  virtual int virt1() { return 150; }
  virtual int virt2() { return 250; }

  int derivedData;
};

int Global2( Base2 * b2 )
{
  return b2->virt2();
}

void main2()
{
  MultipleDerived * md = new MultipleDerived;

 cout<<"md->virt1() "<<md->virt1()<<endl;
 cout<<"Global1(md) "<<Global1( md )<<endl;
 cout<<"md->virt2() "<<md->virt2()<<endl;
 cout<<"Global2(md) "<<Global2(md)<<endl;
 cout<<"Multiple Derived: "<<sizeof(MultipleDerived)<<endl;
}
int main()
{
	main1();
	main2();
	return 0;
}
