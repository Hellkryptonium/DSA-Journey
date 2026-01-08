#include<iostream>
using namespace std;

int diagonalSum(int mat[][3], int n) {
    int sum = 0;

    for(int i=0; i<n; i++) { //rows
        for(int j=0; j<n; j++) { //cols
            if(i == j) { // sum += mat[i][i]
                sum += mat[i][j];
            } else if(j == n-i-1) {
                sum += mat[i][j];
            }
        }
    }

    cout << "Sum = " << sum << endl;
    return sum;
}

int diagonalSum2(int mat[][3], int n) {
    int sum = 0;

    for(int i=0; i<n; i++) { //rows
        sum += mat[i][i];
        if(i != n-i-1){
            sum += mat[i][n-i-1];
        }
    }

    cout << "Sum = " << sum << endl;
    return sum;
}



int main() {
    int matrix[4][4] = {{1,2,3,4},
                        {5,6,7,8},
                        {9,10,11,12},
                        {13,14,15,16}};

    int matrix2[3][3] = {{1,2,3,},
                        {5,6,7},
                        {9,10,11}};


    

    diagonalSum2(matrix2,3);

    return 0;
}