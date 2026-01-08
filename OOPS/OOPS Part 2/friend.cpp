#include<iostream>
#include<string>
using namespace std;

class A {
    string secret = "secret data";
    friend class B;
    friend void revealSecret(A &obj);
};

class B {
public:
    void showSecret(A &obj) {
        cout << obj.secret << endl;
    }
};

void revealSecret(A &obj) {
    cout << obj.secret << endl;
}

int main() {
    
    return 0;
}