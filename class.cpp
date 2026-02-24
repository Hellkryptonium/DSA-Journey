#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> a = {3, -1, 6, 8};
    vector<int> b = {4, 2, 1, 100};
    int sum = 0;
    int l = 0, r = a.size();
    for (int i = a.size() - 1; i >= 0; i--)
    {
        if (i + 1 < a.size())
        {
            a[i] = max(a[i], max(a[i + 1], b[i]));
        }
        else
        {
            a[i] = max(a[i], b[i]);
        }
        sum += a[i];
    }
    for (int num : a)
    {
        cout << num << " " << endl;
    }
    cout << sum << endl;
    return 0;
}