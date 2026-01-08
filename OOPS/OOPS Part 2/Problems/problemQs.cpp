#include<iostream>
#include<string>
using namespace std;

class Parent {
public:
    Parent() {
        cout << "constructr of parent\n";
    }
    ~Parent() {
        cout << "desctructor of parent\n";
    }
};

class Child : public Parent {
public:
    Child() {
        cout << "constructor of child\n";
    }
    ~Child() {
        cout << "desctructor of child\n";
    }
};

int main() {
    Child obj;
    return 0;
}