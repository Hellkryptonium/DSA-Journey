#include <iostream>
using namespace std;

void printArr(int* ptr, int n) {
    for(int i=0; i<n; i++) {
        cout << *ptr << endl;
        ptr++;
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr)/sizeof(int);

    printArr(arr, n);

    return 0;
}