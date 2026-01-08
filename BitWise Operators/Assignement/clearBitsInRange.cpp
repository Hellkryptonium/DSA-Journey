#include <iostream>
using namespace std;

void clearBitsInRange(int num, int i, int j) {
    int a = (~0) << (j+1);
    int b = (1<<i) - 1;
    int bitMask = a | b;
    num = num & bitMask;

    cout << num << endl;
}

int main() {
    clearBitsInRange(31,1,3);
    return 0;
}