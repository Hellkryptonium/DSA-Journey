#include <iostream>
#include <string>
using namespace std;

class Complex {
public:
    int real;
    int img;

    Complex(int real, int img) {
        this->real = real;
        this->img = img;
    }

    void show() {
        cout<< "Complex Number: " << real << " + " << img << "i " << endl;
    }

    Complex operator - (Complex &c2) {
        int resReal = real - c2.real;
        int resImg = img - c2.img;
        return Complex(resReal, resImg);
    }

};


int main() {
    Complex c1(1, 1);
    Complex c2(2, 2);

    Complex c3 = c1 - c2;

    c3.show();
    return 0;
}