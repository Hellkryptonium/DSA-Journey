#include <bits/stdc++.h>
using namespace std;

int targetSum(vector<int> nums, int target)
{
    int n = nums.size();
    vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= target; j++)
        {
            if (nums[i - 1] <= j)
            {
                dp[i][j] = max(nums[i - 1] + dp[i - 1][j - nums[i - 1]], dp[i - 1][j]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n][target] == target;
}

int main()
{
    vector<int> nums = {4, 2, 7, 1, 3};

    cout << targetSum(nums, 10) << endl;
    return 0;
}