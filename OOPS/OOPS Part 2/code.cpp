#include <iostream>
#include <string>
using namespace std; 

class Print {
public: 
    void show(int x) {
        cout << "int: " << x << endl;
    }

    void show(string str) {
        cout << "string: " << str << endl;
    }
};

class Complex {
private:
    int real;
    int img;

public:
    Complex(int r, int i) {
        real = r;
        img = i;
    }

    void showNum() {
        cout << real << " + " << img << "i \n";
    }

    void operator + (Complex &c2) {
        int resReal = this->real + c2.real;
        int resImg = this->img + c2.img;
        // operator overloading
        Complex c3(resReal, resImg);
            cout << "res = ";
              c3.showNum();
    }
};

int main() {
    Complex c1(1, 2);
    Complex c2(3, 4);

    c1 + c2;
    return 0;
}