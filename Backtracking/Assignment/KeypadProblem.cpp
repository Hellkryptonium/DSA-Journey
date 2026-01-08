#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> keypad = {
    {},
    {},
    {"abc"},
    {"def"},
    {"ghi"},
    {"jkl"},
    {"mno"},
    {"pqrs"},
    {"tuv"},
    {"wxyz"},
};

void helper(string input, int pos, int n, string ans)
{
    if (pos == n)
    {
        cout << ans << endl;
    }
    else
    {
        for (int i = 0; i < keypad[input[pos - '0']].size(); i++)
        {
            ans.push_back(keypad[input[pos - '0']][i]);
            helper(input, pos + 1, n, ans);
            ans.pop_back();
        }
    }
}

void letterCombinations(string input)
{
    int n = input.size();
    if (n == 0)
    {
        cout << "No number pressed." << endl;
        return;
    }
    helper(input, 0, n, "");
}

int main()
{
    letterCombinations("2579");

    return 0;
}