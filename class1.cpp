#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> a = {3, 5, 2, 3, 5, 1, 2};

    unordered_map<int, int> freq;
    freq.reserve(a.size());

    for (int x : a)
        freq[x]++;

    for (int x : a)
    {
        if (freq[x] == 1)
        {
            cout << x << endl;
            break;
        }
    }

    return 0;
}