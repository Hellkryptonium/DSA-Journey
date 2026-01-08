#include <iostream>
#include <string>
using namespace std;

class Car {
    string name;
    string color;

public: 
    Car() {
        cout << "constructor without parameters" << endl;
    }

    Car(string name, string color) {
        cout << "constructor is called. object being created..\n";
        this->name = name;
        this->color = color;
    }

    void start() {
        cout << "car has started" << endl;
    }

    void stop() {
        cout << "car has stopped\n";
    }

    // Getter
    string getName() {
        return name;
    }
};

int main() {
    Car c0;
    Car c1("maruti","white");
    Car c2("fortuneer", "blue");

    cout << "car name: " << c1.getName() << endl;
    return 0;
}