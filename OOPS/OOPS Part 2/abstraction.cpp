#include <iostream>
#include <string>
using namespace std;

class Shape {
public:
    virtual void draw() = 0;//pure virtual function
    
};

class Circle : public Shape {
public:
    void draw() {
        cout << "draw square\n";
    }
};

class Square : public Shape {
public: 
    void draw() {
        cout << "draw circle\n";
    }
};

int miain() {
  

    return 0;
}