#include <iostream>
#include <string>
#include <vector>
using namespace std;

void removeDuplicate(string str, string ans, int i, int map[26])
{
    if (i == str.size())
    {
        cout << "ans: " << ans << endl;
        return;
    }

    int mapIdx = (int)(str[i] - 'a'); //'a' - 0

    if (map[mapIdx] == true)
    { // duplicate
        removeDuplicate(str, ans, i + 1, map);
    }
    else
    { // not duplicate
        map[mapIdx] = true;
        removeDuplicate(str, ans + str[i], i + 1, map);
    }
}

void removeDuplicate1(string str, string ans, int map[26])
{
    int n = str.size();

    if (n == 0)
    {
        cout << "ans: " << ans << endl;
        return;
    }
    char ch = str[n - 1];
    int mapIdx = (int)(str[n - 1] - 'a'); //'a' - 0
    str = str.substr(0, n - 1);

    if (map[mapIdx] == true)
    { // duplicate
        removeDuplicate1(str, ans, map);
    }
    else
    { // not duplicate
        map[mapIdx] = true;
        removeDuplicate1(str, ans + ch, map);
    }
}

int main()
{
    string str = "aaabbb";
    string ans = "";
    int map[26] = {false};

    removeDuplicate1(str, ans, map);
    return 0;
}