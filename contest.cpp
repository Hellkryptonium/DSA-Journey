#include <iostream>
#include <string>
#include <vector>
#include <list>
using namespace std;

int longestSubsequence(vector<int> &nums)
{
    vector<int> v;
    if (nums[0] > 0)
    {
        v.push_back(nums[0]);
    }

    for (int i = 1; i < nums.size(); i++)
    {
        int ans = v[0];

        for (int i = 1; i < v.size(); i++)
        {
            int temp = ans;
            ans = ans & v[i];
            if (ans == 0)
            {
                ans = temp;
            }
        }
        if (nums[i - 1] < nums[i])
        {
            v.push_back(nums[i]);
        }
    }

    return v.size();
}

int main()
{

    int count = 1;
    for (int i = 1; i <= 5; i++)
    {

        cout << i << " & " << 1 << " = " << ((i >> 1) & 1) << endl;
    }

    list<int> ll;

    return 0;
}