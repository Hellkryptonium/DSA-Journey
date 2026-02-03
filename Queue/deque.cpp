#include <iostream>
#include <deque>
using namespace std;

int main()
{
    deque<int> deq;

    deq.push_front(2);
    deq.push_back(1);

    deq.push_back(3);

    cout << deq.front();
    return 0;
}