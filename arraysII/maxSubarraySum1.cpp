#include <iostream>
using namespace std;


void maxSubarraySum1(int* arr,int n) {
    int maxSum = INT16_MIN;
    for(int start=0; start<n; start++) {
        for(int end=start; end<n; end++) {
            int currSum = 0;
            for(int i=start; i<=end; i++) {
                currSum += arr[i];
            }
            cout << currSum << ", ";
            maxSum = max(maxSum, currSum);
        }
        cout << endl;

    }
    cout << "Max = " << maxSum;
}


void maxSubarraySum2(int* arr,int n) {// start = 2;
    int maxSum = INT16_MIN;
    for(int start=0; start<n; start++) {// end = 2, 3, 4, 5
        int currSum = 0;
        for(int end=start; end<n; end++) {
            currSum += arr[end];
            cout << currSum;
            maxSum = max(maxSum, currSum);
        }
    }
    cout << "Max = " << maxSum;
}

void maxSubarraySum3(int* arr, int n) {
    int maxSum = INT16_MIN;
    int currSum = 0;
    for(int i=0; i<n; i++) {
        
        currSum += arr[i];
        maxSum = max(maxSum, currSum);

        if(currSum < 0) {
            currSum = 0;
        }
    }
    cout << "Max Subarray Sum using Kadane's algorithm: " << maxSum;
}

int main() {
    int arr[6] = {2, -3, 6, -5, 4, 2};
    int n = sizeof(arr)/sizeof(int);

    maxSubarraySum2(arr,n);
    return 0;
}