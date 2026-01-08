#include <iostream>
using namespace std;

int majorityElement(int arr[], int n)
{
    int count = 0;
    int candidate = 0;
    for (int i = 0; i < n; i++)
    {
        if (count == 0)
            candidate = arr[i];
        count += (candidate == arr[i]) ? 1 : -1;
    }

    return candidate;
}

int main()
{
    int arr[3] = {3, 2, 3};
    int nums[7] = {2, 2, 1, 1, 1, 2, 2};

    cout << majorityElement(arr, 3) << endl;

    cout << majorityElement(nums, 7) << endl;

    return 0;
}