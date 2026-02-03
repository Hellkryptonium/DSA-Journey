#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> A = {4, 1, 8, 7};
    vector<int> B = {2, 3, 6, 7};

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    int absDiff = 0;

    for (int i = 0; i < A.size(); i++)
    {
        absDiff += abs(A[i] - B[i]);
    }

    cout << "Min abs diff = " << absDiff << endl;
    return 0;
}