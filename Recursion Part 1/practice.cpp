#include <iostream>
#include <string>
#include <vector>
using namespace std;

int fact(int n)
{
    if (n < 0)
        return 0;

    if (n == 0)
        return 1;

    return n * fact(n - 1);
}

void decNum(int n)
{
    if (n == 0)
    {
        return;
    }

    cout << n << endl;
    decNum(n - 1);
}

void incNum(int n)
{
    if (n == 0)
        return;

    incNum(n - 1);
    cout << n << endl;
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
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }
    return fib(n - 1) + fib(n - 2);
}

void fibSeries(int n)
{
    int a = 0, b = 1;
    for (int i = 0; i <= n; i++)
    {
        cout << a << " ";
        int next = a + b;
        a = b;
        b = next;
    }
}

bool isSorted(int arr[], int n, int i)
{
    if (i == n)
    {
        return true;
    }

    if (arr[i] > arr[i + 1])
    {
        return false;
    }

    isSorted(arr, n, i + 1);
}

int firstOccur(vector<int> &vec, int i, int target)
{
    if (i == vec.size())
    {
        return -1;
    }

    if (vec[i] == target)
    {
        return i;
    }

    firstOccur(vec, i + 1, target);
}

int lastOccur(vector<int> &vec, int i, int target)
{
    if (i == vec.size())
    {
        return -1;
    }

    int idxFound = lastOccur(vec, i + 1, target);
    if (idxFound == -1 && vec[i] == target)
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
    cout << pow(10, 10);

    return 0;
}