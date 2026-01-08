#include <iostream>
#include <vector>
using namespace std;

int mergeAndCount(vector<int> &arr, int left, int mid, int right)
{
    int i = left;
    int j = mid + 1;
    int invCount = 0;
    vector<int> temp;

    while (i <= mid && j <= right)
    {
        if (arr[i] <= arr[j])
        {
            temp.push_back(arr[i]);
            i++;
        }
        else
        {
            temp.push_back(arr[j]);
            invCount += (mid - i + 1);
            j++;
        }
    }

    while (i <= mid)
    {
        temp.push_back(arr[i]);
        i++;
    }

    while (j <= right)
    {
        temp.push_back(arr[j]);
        j++;
    }

    for (int k = left, t = 0; k <= right; k++, t++)
    {
        arr[k] = temp[t];
    }

    return invCount;
}

int mergeSort(vector<int> &arr, int left, int right)
{
    if (left >= right)
        return 0;

    int mid = left + (right - left) / 2;

    int count = 0;
    count += mergeSort(arr, left, mid);
    count += mergeSort(arr, mid + 1, right);
    count += mergeAndCount(arr, left, mid, right);

    return count;
}

int getInversions(vector<int> &arr)
{
    return mergeSort(arr, 0, arr.size() - 1);
}

int main()
{
    vector<int> arr = {2, 4, 1, 3, 5};
    cout << "Inversions = " << getInversions(arr) << endl;

    return 0;
}