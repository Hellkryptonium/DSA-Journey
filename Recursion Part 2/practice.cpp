#include <iostream>
#include <string>
#include <vector>
using namespace std;

int tp(int n)
{
    if (n == 0 || n == 1)
        return 1;

    return tp(n - 1) + tp(n - 2);
}

void removeDuplicaes(string str, string ans, int i, int arr[26])
{
    if (i == str.size())
    {
        cout << "ans: " << ans << endl;
        return;
    }

    int mapIdx = (int)(str[i] - 'a');

    if (arr[mapIdx] == true)
    {
        // duplicate
        removeDuplicaes(str, ans, i + 1, arr);
    }
    else
    {
        // not duplicate
        arr[mapIdx] = true;
        removeDuplicaes(str, ans + str[i], i + 1, arr);
    }
}

void removeDuplicate(string str, string ans, int arr[26])
{
    int n = str.size();

    if (n == 0)
    {
        cout << "ans: " << ans << endl;
        return;
    }

    char ch = str[n - 1];
    int mapIdx = (int)(str[n - 1] - 'a');
    str = str.substr(0, n - 1);

    if (arr[mapIdx] == true)
    {
        // duplicate
        removeDuplicate(str, ans, arr);
    }
    else
    {
        arr[mapIdx] = true;
        removeDuplicate(str, ans + ch, arr);
    }
}

int main()
{
    string str = "abb";
    string ans = "";
    int arr[26] = {false};

    removeDuplicaes(str, ans, 0, arr);
    return 0;
}