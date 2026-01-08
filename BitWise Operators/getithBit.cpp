#include <iostream>
using namespace std;

int getIthBit(int num, int i) {
    int bitMask = i << 1;
    if(!(num & bitMask)) {
        return 0;
    } else {
        return 1;
    }
}

int main() {
    cout << getIthBit(6,2);
    return 0;
}