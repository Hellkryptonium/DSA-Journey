#include <bits/stdc++.h>
using namespace std;

int main()
{
    // // key, val
    // unordered_map<string, int> m;

    // m["China"] = 150;
    // m["India"] = 150;
    // m["US"] = 50;
    // m["Nepal"] = 10;

    // cout << 10;
    // for (pair<string, int> country : m)
    // {
    //     cout << country.first << " ," << country.second << endl;
    // }

    // m.count("nepal");
    // m.erase("Nepal");

    // map<string, int> m;

    // m["China"] = 150;
    // m["India"] = 150;
    // m["US"] = 50;
    // m["Nepal"] = 10;

    // cout << 10;
    // for (pair<string, int> country : m)
    // {
    //     cout << country.first << " ," << country.second << endl;
    // }

    // m.count("nepal");
    // m.erase("Nepal");

    // unordered_set<int> s;

    // s.insert(1);
    // s.insert(2);
    // s.insert(2);

    // cout << s.size();

    // if (s.find(3) != s.end())
    // {
    //     cout << "3 exists\n";

    set<int> s;

    s.insert(1);
    s.insert(2);
    s.insert(3);

    for (int l : s)
    {
        cout << l << endl;
    }
    return 0;
}