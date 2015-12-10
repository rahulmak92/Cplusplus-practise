// Quiz 7
// Fall 2014

#include <iostream>
#include <iomanip>
using namespace std;

class Asset {
private:
    string name;
    float price;
public:
    Asset(string n, float p) {name = n; price = p;}
    string getName()  { return name; }
    void setName(string n) {name = n; }
    float getPrice() { return price; }
    void setPrice(float p) { price = p;}
    virtual float calcRent() = 0;
    
};

class Property : public Asset {
  public:
    Property(string n, float p) : Asset (n,p) { }
    float calcRent() {
        return 0.15*getPrice() - 6.5;
    }
};

class Railroad : public Asset {
private:
    int numberOwned;
public:
    Railroad(string n, float p, int no) : Asset (n,p) {
        numberOwned = no;
    }
    float calcRent() {
        switch (numberOwned) {
            case 1: return 25;
            case 2: return 50;
            case 3: return 100;
            case 4: return 200;
        };
        return 0;
    }
};

void showAsset(Asset *list[], int count) {
    
    for (int i=0; i<count; i++) {
        cout << list[i]->getName();  cout << "  ";
        cout << list[i]->calcRent() << endl;
    }
}
// not part of the solution, included so this file will compile and execute.
int main () {
    Asset *collection[] = {
        new Property("Pacific Avenue", 60),
        new Railroad("B&O", 200, 1),
        new Property("Park Place",350)
    };
    
    cout << setprecision(2) << fixed;
    showAsset(collection,3);
}