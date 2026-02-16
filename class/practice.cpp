#include <iostream>
#include <vector>
using namespace std;

int bSearch(vector<int> arr, int val, int lo, int hi)
{
    while (lo < hi)
    {
        int mid = lo + (hi - lo) / 2;
        if (arr[mid] == val)
        {
            return mid;
        }
        else if (arr[mid] < val)
        {
            lo = mid - 1;
        }
        else
        {
            hi = mid + 1;
        }
    }
    return -1;
}

int bSearch1(vector<int> arr, int val, int lo, int hi)
{

    if (lo > hi)
    {
        return -1;
    }
    int mid = lo + (hi - lo) / 2;
    if (arr[mid] == val)
    {
        return mid;
    }

    else if (arr[mid] < val)
    {
        return bSearch1(arr, val, mid - 1, hi);
    }
    else
    {
        return bSearch1(arr, val, lo, mid + 1);
    }
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    cout << bSearch1(arr, 4, 0, arr.size() - 1);

    return 0;
}