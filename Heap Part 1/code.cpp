#include <bits/stdc++.h>
using namespace std;

int main()
{
    priority_queue<string, vector<string>, greater<string>> pq;

    pq.push("theworld");
    pq.push("apnaccllege");
    pq.push("9");
    pq.push("7");
    pq.push("3");

    while (!pq.empty())
    {
        cout << "top : " << pq.top() << endl;
        pq.pop();
    }

    return 0;
}