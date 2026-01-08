#include <iostream>
using namespace std;

void oddOrEven(int num) {
    if(!(num & 1)) {
        cout << "even\n";
    } else {
        cout << "odd\n";
    }
}

int main() {
    oddOrEven(19);
    return 0;
}