#include <iostream>
#include <string>
using namespace std;

void binaryString1(int n, int lastPlace, string ans)
{

    if (n == 0)
    {
        cout << ans << endl;
        return;
    }

    if (lastPlace != 1)
    {
        binaryString1(n - 1, 0, ans + '0');
        binaryString1(n - 1, 0, ans + '1');
    }
    else
    {
        binaryString1(n - 1, 0, ans + '0');
    }
}

void binaryString(int n, string ans)
{

    if (n == 0)
    {
        cout << ans << endl;
        return;
    }

    if (ans[ans.size() - 1] != '1')
    {
        binaryString(n - 1, ans + '0');
        binaryString(n - 1, ans + '1');
    }
    else
    {
        binaryString(n - 1, ans + '0');
    }
}

int main()
{
    string ans = "";
    binaryString(3, ans);
    return 0;
}