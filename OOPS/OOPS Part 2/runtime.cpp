#include<iostream>
#include<string>
using namespace std;

class Parent {
public:
    void show() {
        cout << "parent class show..\n";
    }

    virtual void hello() {
        cout << "parent class virtual";
    }
};

class Child : public Parent {
public:
    void show() {
        cout << "child class..\n";
    }
    void hello() {
        cout << "child class virtual\n";
    }

};

int main() {
    Child child1;
    Parent *ptr;

    ptr = &child1; // Run time binding

    ptr->hello();
    return 0;
}