#include <bits/stdc++.h>
using namespace std;

int knapsackRec(vector<int> &val, vector<int> &wt, int W, int n)
{
    if (n == 0 || W == 0)
        return 0;

    int itemWt = wt[n - 1];
    int itemVal = val[n - 1];

    if (itemWt <= W)
    { // valid wt
        // include
        int ans1 = knapsackRec(val, wt, W - itemWt, n - 1) + itemVal;

        // exclude
        int ans2 = knapsackRec(val, wt, W, n - 1);

        return max(ans1, ans2);
    }
    else
    {
        // exclude
        return knapsackRec(val, wt, W, n - 1);
    }
}

int knapsackMem(vector<int> &val, vector<int> &wt, int W, int n, vector<vector<int>> &dp)
{
    if (n == 0 || W == 0)
        return 0;

    if (dp[n][W] != -1)
    {
        return dp[n][W];
    }

    int itemWt = wt[n - 1];
    int itemVal = val[n - 1];

    if (itemWt <= W)
    { // valid wt
        // include
        int ans1 = knapsackMem(val, wt, W - itemWt, n - 1, dp) + itemVal;

        // exclude
        int ans2 = knapsackMem(val, wt, W, n - 1, dp);

        dp[n][W] = max(ans1, ans2);
    }
    else
    {
        // exclude
        dp[n][W] = knapsackMem(val, wt, W, n - 1, dp);
    }

    return dp[n][W];
}

int knapsackTab(vector<int> val, vector<int> wt, int W, int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < W + 1; j++)
        {
            int itemWt = wt[i - 1];
            int itemVal = val[i - 1];

            if (itemWt <= j)
            {
                dp[i][j] = max(itemVal + dp[i - 1][j - itemWt], dp[i - 1][j]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][W];
}

int main()
{
    vector<int> val = {15, 14, 10, 45, 30};
    vector<int> wt = {2, 5, 1, 3, 4};
    int w = 7;
    int n = 5;

    vector<vector<int>> dp(n + 1, vector<int>(w + 1, -1));

    cout << knapsackTab(val, wt, w, n) << endl;

    return 0;
}