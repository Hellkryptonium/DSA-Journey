#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> a = {1, 2, 3, 5};
    int n = 5;
    int sum = 0;
    for (int s : a)
    {
        sum += s;
    }
    int actualSum = (n * (n + 1)) / 2;

    cout << actualSum - sum;

    return 0;
}