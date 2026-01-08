#include <iostream>
using namespace std;

void updateIthBith (int num, int i, int val) {
    num = num & ~(1 << i); //clear ith bit

    num = num | (val << i);

    cout << num << endl;
}

int main() {
    updateIthBith(7,2,0);
    updateIthBith(7,3,1);
    return 0;
}