#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    vector<int> nums = {3, 2, 8, 5, 4, 14, 9, 15};

    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        int x = nums[i];
        int even = 0;
        int odd = 0;
        for (int j = i + 1; j <= n; j++)
        {
            x = x ^ nums[j];
            if (nums[j - 1] % 2 == 0)
            {
                even++;
            }
            else
            {
                odd++;
            }
        }

        if (even == odd && x == 0)
            cout << even * 2 << " ";
    }

    return 0;
}