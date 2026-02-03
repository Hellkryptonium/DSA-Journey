#include <iostream>
#include <deque>
using namespace std;

class Stack
{
    deque<int> deq;

public:
    void push(int data)
    {
        deq.push_front(data);
    }

    void pop()
    {
        deq.pop_front();
    }

    int top()
    {
        return deq.front();
    }
};

int main()
{
    return 0;
}