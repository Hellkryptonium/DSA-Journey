#include <iostream>
using namespace std;

void print(int arr[], int n) {
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
}

void bubbleSort(int arr[], int n) {
    for(int i=0; i<n; i++) {
        cout << "Inner Loop";
        bool isSwap = false;
        for(int j=0; j<n-i-1; j++) {
            if(arr[j] < arr[j+1]) {
                swap(arr[j], arr[j+1]);
                isSwap = true;
            }
            cout << "Inner Loop";
        }
        if(!isSwap) {
            return;
        }
    }
    cout << "Sorted Array:";
    print(arr,n);
}

int main() {
    int arr[5] = {1,2,3,4,5};
    int n = sizeof(arr)/sizeof(int);

    bubbleSort(arr,n);

    return 0;
}