#include<iostream>
#include<algorithm>
using namespace std;

void print(int arr[], int n) {
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
}

int main() {
    int arr[8] = {1,4,2,3,34,5,2,};
    sort(arr, arr+8,greater<int>());

    print(arr,8);
    return 0;
}