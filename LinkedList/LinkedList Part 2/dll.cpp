#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int val)
    {
        data = val;
        prev = next = nullptr;
    }
};

class DoublyList
{
public:
    Node *head;
    Node *tail;

    DoublyList()
    {
        head = tail = nullptr;
    }

    void push_front(int val)
    {
        Node *newNode = new Node(val);

        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void pop_front()
    {
        Node *temp = head;
        head = head->next;
        if (head != nullptr)
        {
            head->prev = nullptr;
        }
        temp->next = nullptr;
        delete temp;
    }

    void push_back(int val)
    {
        Node *newNode = new Node(val);
        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            Node *temp = head;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
        }
    }

    void pop_back()
    {
        if (head == nullptr)
        {
            cout << "List is empty\n";
        }

        if (head->next == nullptr)
        {
            delete head;
            head = nullptr;
            return;
        }

        Node *temp = head;

        while (temp->next)
        {
            temp = temp->next;
        }

        temp->prev->next = nullptr;
        delete temp;
    }

    void printList()
    {
        Node *temp = head;
        while (temp)
        {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }

        cout << "nullptr" << endl;
    }
};

int main()
{
    DoublyList dbll;

    dbll.push_back(4);
    dbll.push_back(3);
    dbll.push_back(2);
    dbll.push_back(1);

    dbll.printList();

    dbll.pop_back();
    dbll.pop_back();

    dbll.printList();

    return 0;
}