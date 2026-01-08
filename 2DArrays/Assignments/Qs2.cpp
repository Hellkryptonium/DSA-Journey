#include <iostream>
#include <numeric>
using namespace std;

void sum2ndRow(int arr[][3], int n, int m) {
    int sum=0;
    for(int j=0; j<m; j++) {
        sum += arr[1][j];
    }
    cout << "sum2ndRow = " << sum << endl;
}


int main() {
    int nums[3][3] = {{1,4,9}, 
                    {11,4,3},
                    {2,2,3}};
    sum2ndRow(nums,3,3);
    int sum = accumulate(begin(nums[1]),end(nums[1]),0);
    cout << sum;
    return 0;
}