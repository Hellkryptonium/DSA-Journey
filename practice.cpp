#include <iostream>
#include <vector>
using namespace std;

void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

void insertBeg(int arr[], int n, int num)
{
    for (int i = n; i > 0; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[0] = num;
    print(arr, n);
}

void insertEnd(int arr[], int n, int num)
{
    vector<int> newArr(n + 1);
    for (int i = 0; i < n; i++)
    {
        newArr.push_back(arr[i]);
    }
    newArr.push_back(num);
}

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        bool isSwap = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                isSwap = true;
            }
        }
        if (!isSwap)
        {
            break;
        }
    }
    print(arr, n);
}

void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIdx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIdx])
            {
                minIdx = j;
            }
            swap(arr[i], arr[minIdx]);
        }
    }
    print(arr, n);
}

int binarySearch(int arr[], int key, int n)
{
    int st = 0, end = n - 1;
    while (st <= end)
    {
        int mid = (end + st) / 2;
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] < key)
        {
            st = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return -1;
}

void bubbleSort2(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        bool isSwap = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                isSwap = true;
            }
        }
        if (!isSwap)
        {
            return;
        }
    }
}

void selectionSort2(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int minIdx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIdx])
            {
                minIdx = j;
            }
            swap(arr[i], arr[minIdx]);
        }
    }
}

int main()
{
    int arr[] = {
        -1,
        0,
        1,
        2,
        3,
        4,
        5,
    };
    int n = sizeof(arr) / sizeof(int);

    int m = 5 / 2;

    cout << m;

    return 0;
}