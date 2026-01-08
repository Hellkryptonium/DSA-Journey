#include <iostream>
using namespace std;

void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

void reverseArray(int arr[], int n)
{
    int copyArr[2];
    for (int i = 0; i < n; i++)
    {
        int j = n - i - 1;
        copyArr[i] = arr[j];
    }
    for (int i = 0; i < n; i++)
    {
        arr[i] = copyArr[i];
    }
    print(arr, n);
}

void reverseArray2(int arr[], int n)
{
    int st = 0, end = n - 1;
    while (st <= end)
    {
        swap(arr[st], arr[end]);
        st++;
        end--;
    }
    print(arr, n);
}

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(int);

    reverseArray2(arr, n);

    return 0;
}