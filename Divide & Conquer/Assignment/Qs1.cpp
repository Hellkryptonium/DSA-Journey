#include <iostream>
#include <vector>
using namespace std;

void merge(string arr[], int si, int mid, int ei)
{
    vector<string> temp;
    int i = si;
    int j = mid + 1;

    while (i <= mid && j <= ei)
    {
        if (arr[i] <= arr[j])
        {
            temp.push_back(arr[i++]);
        }
        else
        {
            temp.push_back(arr[j++]);
        }
    }

    while (i <= mid)
    {
        temp.push_back(arr[i++]);
    }

    while (j <= si)
    {
        temp.push_back(arr[j++]);
    }

    for (int i = si, x = 0; i <= ei; i++)
    {
        arr[i] = temp[x++];
    }
}

void mergeSort(string arr[], int si, int ei)
{
    if (si >= ei)
        return;

    int mid = si + (ei - si) / 2;

    mergeSort(arr, si, mid);
    mergeSort(arr, mid + 1, ei);

    merge(arr, si, mid, ei);
}

int main()
{
    string arr[5] = {"sun", "earth", "mars", "mercury"};

    mergeSort(arr, 0, 4);

    for (string s : arr)
    {
        cout << s << " ";
    }

    return 0;
}