#include <iostream>
#include <vector>
using namespace std;

void allOccur(int arr[], int n, int i, int key)
{

    if (arr[i] == key)
    {
        cout << "ans : " << i << " ";
    }

    if (i == n)
    {
        return;
    }

    allOccur(arr, n, i + 1, key);
}

int main()
{
    int arr[] = {3, 2, 4, 5, 6, 7, 2, 2};
    int key = 2;
    int n = 7;
    allOccur(arr, n, 0, key);
    return 0;
}