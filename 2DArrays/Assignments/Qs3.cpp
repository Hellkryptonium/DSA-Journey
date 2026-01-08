#include <iostream>
using namespace std;

void print(int arr[][3], int n, int m) {
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void transpose(int arr[][3], int n, int m) {
    int result[3][3];
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            result[i][j] = arr[j][i];
            
        }
    }
    print(result,n,m);
}

void transpose2(int arr[][3], int n, int m) {
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<m; j++) {
            swap(arr[i][j],arr[j][i]);
            
        }
    }
    print(arr,n,m);
}

int main() {
    int nums[3][3] = {{1,4,9}, 
                    {11,4,3},
                    {2,2,3}};
    transpose(nums,3,3);
    return 0;
}