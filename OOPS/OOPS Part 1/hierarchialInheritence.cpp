#include <iostream>
#include <string>
using namespace std;

class Animal {
public:
    void eat() {
        cout << "eats";
    }

    void breathe() {
        cout << "breathes";
    }
};

class Bird : public Animal {
public:
    void fly() {
        cout << "bird flies" << endl;
    }
};



int main() {

}