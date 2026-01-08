#include <iostream>
using namespace std;

int isPowerOf2(int num) {
    if(!(num & (num-1))) {
        return true;
    } else {
        return false;
    }
}

int main() {
    cout << isPowerOf2(0);
    return 0;
}