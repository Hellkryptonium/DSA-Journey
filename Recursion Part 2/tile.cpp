#include <iostream>
#include <string>
#include <vector>
using namespace std;

int tilingProblem(int n)
{ // 2*n
    if (n == 0 || n == 1)
        return 1;
    // vertical                    // horizontal
    return tilingProblem(n - 1) + tilingProblem(n - 2);
}

int main()
{
    int n = 4;

    cout << tilingProblem(5) << endl;
    return 0;
}