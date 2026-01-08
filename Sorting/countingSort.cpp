#include <iostream>
#include <vector>
using namespace std;

void print(int arr[], int n) {
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
}

void countSort(int arr[], int n) {
    int freq[10000] = {0};
    int minVal = INT16_MAX, maxVal = INT16_MIN;
    for(int i=0; i<n; i++) {
        minVal = min(minVal, arr[i]);
        maxVal = max(minVal, arr[i]);
    }
    //1st step - O(n)
    for(int i=0; i<n; i++) {
        freq[arr[i]]++;
    }

    //2nd step - O(range)
    for(int i=minVal, j=0; i<=maxVal; i++) {
        while(freq[i]>0) {
            arr[j++] = i;
            freq[i]--;
        }
    }

    print(arr,n);
}

void countSort2(int arr[], int n ) {
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
    int arr[8] = {1, 4, 1, 3, 2, 4, 3, 7};

    countSort(arr,8);

    return 0;
}