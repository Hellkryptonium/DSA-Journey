#include <iostream>
#include <vector>
using namespace std;

void func()
{
    cout << "function call ..." << endl;
    func();
}

int factorial(int n)
{
    if (n < 0)
    {
        return 0;
    }
    if (n == 0)
    {
        return 1;
    }
    return n * factorial(n - 1);
}

void decNumOrder(int n)
{
    if (n == 0)
    {
        return;
    }
    decNumOrder(n - 1);
    cout << n << " ";
}

int sum(int n)
{
    if (n == 1)
    {
        return 1;
    }
    return n + sum(n - 1);
}

int fib(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return fib(n - 1) + fib(n - 2);
}

bool isSorted(int arr[], int n, int i)
{
    if (i == n - 1)
    {
        return true;
    }

    if (arr[i] > arr[i + 1])
    {
        return false;
    }

    return isSorted(arr, n, i + 1);
}

int firstOccur(vector<int> &vec, int i, int target)
{
    if (i == vec.size())
        return -1;
    if (vec[i] == target)
        return i;
    firstOccur(vec, i + 1, target);
}

int lastOccur(vector<int> arr, int target, int i)
{
    if (i == arr.size())
    {
        return -1;
    }
    int idxFound = lastOccur(arr, target, i + 1);
    if (idxFound == -1 && arr[i] == target)
    {
        return i;
    }

    return idxFound;
}

int pow1(int x, int n)
{
    if (n == 0)
    {
        return 1;
    }
    return x * pow1(x, n - 1);
}
// tc O(log n)
int pow(int x, int n)
{
    if (n == 0)
    {
        return 1;
    }
    int halfPow = pow(x, n / 2);
    int halfPowSquare = halfPow * halfPow;
    if (n % 2 != 0)
    {
        return x * halfPowSquare;
    }
    return halfPowSquare;
}

int main()
{
    vector<int> vec = {1, 2, 3, 3, 3, 3, 4, 5}; // sorted

    // cout << firstOccur(vec, 0, 5) << endl;
    // cout << lastOccur(vec, 3, 0);

    decNumOrder(10);

    return 0;
}