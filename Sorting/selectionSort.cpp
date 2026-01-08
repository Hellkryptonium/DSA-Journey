#include <iostream>
using namespace std;

void print(int arr[], int n) {
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
}

void selectionSort(int arr[], int n) {
    for(int i=0; i<n-1; i++) {
        int minIdx = i;
        for(int j=i+1; j<n; j++) {
            if(arr[j] > arr[minIdx]) {
                minIdx = j;
            }
            swap(arr[j], arr[minIdx]);
        }
    }
    print(arr,n);
}

int main() {
    int arr[5] = {1,6,3,4,5};
    int n = sizeof(arr)/sizeof(int);

    selectionSort(arr,n);

    return 0;
}