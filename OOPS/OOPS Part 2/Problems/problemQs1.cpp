#include<iostream>
#include<string>
using namespace std;

class Base {
public:
    virtual void print() {
        cout<< "base\n";
    }
};

class Derived : public Base {
public:
    void print() {
        cout << "derived\n";
    }
};

int main() {
    Base *b = new Derived();
    b->print();
    return 0;
}