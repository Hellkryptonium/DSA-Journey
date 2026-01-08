#include <iostream>
#include <vector>
using namespace std;

void print(int arr[], int n) {
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
}

void bubbleSort(int arr[], int n) {
    for(int i=0; i<n; i++) {
        bool isSwap = false;
        for(int j=0; j<n-i-1; j++) {
            if(arr[j]>arr[j+1]) {
                swap(arr[j],arr[j+1]);
            }
            isSwap = true;
        }
        if(!isSwap) {
            break;
        }
       
    }
    print(arr,n);
}

void selectionSort(int arr[], int n) {
    for(int i=0; i<n; i++) {
        int minIdx = i;
        for(int j=i+1; j<n; j++) {
            if(arr[j] < arr[minIdx]) {
                minIdx = j;
            }
            swap(arr[i],arr[minIdx]);
        }
    }
    print(arr,n);
}

void insertionSort(int arr[], int n) {
    for(int i=1; i<n; i++) {
        int curr=arr[i];
        int prev = i - 1;
        while(prev >= 0 && arr[prev] > curr) {
            arr[prev+1] = arr[prev];
            prev--;
        }
        arr[prev + 1] = curr;
    }
}

void countSort(int arr[], int n ) {
    int minVal = INT16_MAX, maxVal = INT16_MIN;

    for(int i=0; i<n; i++) {
        minVal = min(minVal, arr[i]);
        maxVal = max(maxVal, arr[i]);
    }

    int range = maxVal - minVal + 1;
    vector<int> freq(range,0);

    for(int i=0; i<n; i++) {
        freq[arr[i] - minVal]++;
    }

    int j = 0;
    for(int i = minVal; i <= maxVal; i++) {
        while(freq[i - minVal] > 0) {
            arr[j++] = i;
            freq[i-minVal]--;
        }
    }
    print(arr,n);
}

int main() {
    int arr[] = {19,2,3,42,5};
    int n = sizeof(arr)/sizeof(int);

    countSort(arr,n);

    return 0;
}