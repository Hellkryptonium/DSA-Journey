#include <bits/stdc++.h>
using namespace std;

int countWaysRec(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }

    return countWaysRec(n - 1) + countWaysRec(n - 2);
}

int countWaysMem(int n, vector<int> &dp)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }

    if (dp[n] != -1)
    {
        return dp[n];
    }

    dp[n] = countWaysMem(n - 1, dp) + countWaysMem(n - 2, dp);

    return dp[n];
}

int countWaysTb(int n) // 1, 2, 3, 4 //variation on climbing stairs variation
{
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }

    return dp[n];
}

int main()
{
    int n = 4;
    vector<int> dp(n + 1, -1);
    cout << countWaysTb(n) << endl;
    return 0;
}