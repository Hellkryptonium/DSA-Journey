#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        this->data = val;
        next = nullptr;
    }

    ~Node()
    {
        if (next != nullptr)
        {
            delete next;
            next = nullptr;
        }
    }
};

class List
{
public:
    Node *head;
    Node *tail;

    List()
    {
        head = nullptr;
        tail = nullptr;
    }

    ~List()
    {
        if (head != nullptr)
        {
            delete head;
            head = nullptr;
        }
    }

    void push_front(int val)
    {
        Node *newNode = new Node(val); // dynamic
        if (head == nullptr)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }

    void push_back(int val)
    {
        Node *newNode = new Node(val);
        if (head == nullptr)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void printList()
    {
        Node *temp = head;
        while (temp)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "nullptr" << endl;
    }

    void insert(int val, int pos)
    {
        Node *newNode = new Node(val);

        Node *temp = head;
        for (int i = 0; i < pos - 1; i++)
        {
            if (temp == nullptr)
            {
                cout << "position is invalid\n";
            }
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void pop_front()
    {
        if (head == nullptr)
        {
            cout << "LL is empty\n";
        }
        Node *temp = head;

        head = head->next;
        temp->next = nullptr;
        delete temp;
    }

    void pop_back()
    {
        if (head == nullptr)
        {
            cout << "LL is empty\n";
        }

        Node *temp = head;

        while (temp->next->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = nullptr;
        delete tail;
        tail = temp;
    }

    int searchItr(int val)
    {
        if (head == nullptr)
        {
            cout << "LL is empty\n";
        }

        Node *temp = head;
        int pos = 0;
        while (temp != nullptr)
        {
            if (temp->data == val)
            {
                return pos;
            }
            pos++;
            temp = temp->next;
        }
        return -1;
    }

    int helper(Node *temp, int key)
    {
        if (temp == nullptr)
            return -1;

        if (temp->data == key)
        {
            return 0;
        }

        int idx = helper(temp->next, key);

        if (idx == -1)
            return -1;

        return idx + 1;
    }
    int searchRec(int key)
    {
        return helper(head, key);
    }

    void reverse()
    {
        Node *curr = head;
        Node *prev = nullptr;

        while (curr != nullptr)
        {
            Node *next = curr->next;
            curr->next = prev;

            prev = curr;
            curr = next;
        }
        head = prev;
    }

    int getSize()
    {
        int sz = 0;
        Node *temp = head;
        while (temp)
        {
            temp = temp->next;
            sz++;
        }
        return sz;
    }

    void removeNth(int n)
    {
        Node *prev = head;
        int size = getSize();
        for (int i = 1; i < (size - n); i++)
        {
            prev = prev->next;
        }
        Node *toDel = prev->next;
        cout << "going to delete : " << toDel->data << endl;
        prev->next = prev->next->next;
    }
};

int main()
{
    List ll;

    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);
    ll.push_back(4);
    ll.push_back(5);

    ll.printList();

    ll.insert(100, 2);

    ll.pop_front();
    ll.pop_back();
    ll.printList();

    cout << ll.searchRec(100) << endl;

    ll.reverse();

    ll.printList();

    ll.removeNth(2);
    ll.printList();

    return 0;
}