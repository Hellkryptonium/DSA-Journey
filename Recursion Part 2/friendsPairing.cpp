#include <iostream>
#include <string>
using namespace std;

int friendsPairing(int n)
{
    if (n <= 1)
    {
        return n;
    } // alternative
    if (n == 1 || n == 2)
    {
        return n;
    }
    //   single                             //pairing
    return 1 * friendsPairing(n - 1) + (n - 1) * friendsPairing(n - 2);
}

int main()
{
    cout << friendsPairing(4) << endl;

    return 0;
}