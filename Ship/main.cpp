#include<iostream>
using namespace std;

class Ship {

protected:
	string sname;
	string syear;

public:

	Ship(string a, string b) {
		sname = a;
		syear = b;
	}

	Ship() {
		sname = "";
	}

	string getsname() {
		return sname;
	}

	string getsyear() {
		return syear;
	}

	void setsname(string n) {
		sname = n;
	}

	void setsyear(string y) {
		syear = y;
	}

	virtual void print() {
		cout << "Ship Name: " << sname << " & Year: " << syear << endl;
	}

};

class CruiseShip: public Ship {

private:
	int maxp; //maximum num of passengers

public:

	CruiseShip() {
		maxp = 0;
	}

	CruiseShip(int a, string sname, string year) :
			Ship(sname, year) {
		maxp = a;
	}

	int getmaxp() {
		return maxp;
	}

	void setmaxp(int p) {
		maxp = p;
	}

	void print() {
//cout<<Ship::getsname()<<endl;
		cout << " Maximum Passengers: " << maxp << endl;
	}

};

class CargoShip: public Ship {

private:
	int capacity; //cargo capacity in tonnage

public:

	CargoShip() {
		capacity = 0;
	}
	;

	CargoShip(int a, string name, string year) :
			Ship(name, year) {
		capacity = a;
	}

	int getcapacity() {
		return capacity;
	}

	void setcapacity(int c) {
		capacity = c;
	}

	void print() {
//cout<<Ship::getsname()<<endl;
		cout << " Cargo Capacity: " << capacity << endl;
	}
};

int main() {

//const int Size=3;

	Ship *ptr[] = { new Ship("cnn", "1928"), new CruiseShip(23, "vishal",
			"1992"), new CargoShip(300, "pavan", "1900") };

	for (int i = 0; i < 3; i++) {
		cout << ptr[i]->print() << endl;
	}
}
