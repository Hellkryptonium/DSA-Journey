#include <iostream>
#include <list>
#include <stack>
using namespace std;

// create Stack suing linked list
template <class T>
class Node
{
public:
    T data;
    Node *next;

    Node(T val)
    {
        data = val;
        next = nullptr;
    }
};

template <class T>
class Stack
{
    Node<T> *head;

public:
    Stack()
    {
        head = nullptr;
    }

    void push(T val)
    {
        // push-front
        Node<T> *newNode = new Node<T>(val);
        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }

    void pop()
    {
        // pop-front
        Node<T> *temp = head;
        head = head->next;
        temp->next = nullptr;
        delete temp;
    }

    T top()
    {
        return head->data;
    }

    bool isEmpty()
    {
        return head == nullptr;
    }
};

int main()
{
    stack<int> s;

    s.push(3);
    s.push(2);
    s.push(1);

    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }

    cout << endl;

    return 0;
}