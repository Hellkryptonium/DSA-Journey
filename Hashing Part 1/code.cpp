#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    string key;
    int val;
    Node *next;

    Node(string key, int val)
    {
        this->key = key;
        this->val = val;
        next = nullptr;
    }

    ~Node()
    {
        if (next != nullptr)
        {
            delete next;
        }
    }
};

class HashTable
{
public:
    int totSize;
    int currSize; // reshaing
    Node **table;

    int HashFunction(string key)
    {
        int idx = 0;

        for (int i = 0; i < key.size(); i++)
        {
            idx = idx + (key[i] * key[i]) % totSize;
        }

        return idx % totSize;
    }

    void rehash()
    {
        Node **oldTable = table;
        int oldSize = totSize;

        totSize = 2 * totSize;
        currSize = 0;
        table = new Node *[totSize];

        for (int i = 0; i < totSize; i++)
        {
            table[i] = nullptr;
        }

        for (int i = 0; i < oldSize; i++)
        {
            Node *temp = oldTable[i];
            while (temp != nullptr)
            {
                insert(temp->key, temp->val);
                temp = temp->next;
            }

            if (oldTable[i] != nullptr)
            {
                delete oldTable[i];
            }
        }
        delete[] oldTable;
    }

public:
    HashTable(int size)
    {
        totSize = size;
        currSize = 0;

        table = new Node *[totSize];

        for (int i = 0; i < totSize; i++)
        {
            table[i] = nullptr;
        }
    }

    void insert(string key, int val)
    {
        int idx = HashFunction(key);

        Node *newNode = new Node(key, val);

        newNode->next = table[idx];
        table[idx] = newNode;

        currSize++;

        double lambda = currSize / (double)totSize;

        if (lambda > 1)
        {
            rehash(); // O(n)
        }
    }

    bool exists(string key)
    {
        int idx = HashFunction(key);

        Node *temp = table[idx];
        while (temp != nullptr)
        {
            if (temp->key == key)
            {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    int search(string key)
    {
        int idx = HashFunction(key);

        Node *temp = table[idx];
        while (temp != nullptr)
        {
            if (temp->key == key)
            {
                return temp->val;
            }
            temp = temp->next;
        }
        return -1;
    }

    void remove(string key)
    {
        int idx = HashFunction(key);

        Node *temp = table[idx];
        Node *prev = temp;
        while (temp != nullptr)
        {
            if (temp->key == key)
            {
                if (prev == temp)
                {
                    table[idx] = temp->next;
                }
                else
                {
                    prev->next = temp->next;
                }
                break;
            }
            prev = temp;
            temp = temp->next;
        }
    }

    void print()
    {
        for (int i = 0; i < totSize; i++)
        {
            cout << "idx" << i << "->";
            Node *temp = table[i];
            while (temp != nullptr)
            {
                cout << "(" << temp->key << "," << temp->val << ") -> ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
};

int main()
{
    HashTable ht(10);

    ht.insert("India", 150);
    ht.insert("China", 150);
    ht.insert("US", 50);
    ht.insert("Nepal", 10);
    ht.insert("UK", 20);

    if (ht.exists("Canada"))
    {
        cout << "India population : " << ht.search("Nepal") << endl;
    }
    ht.print();
    ht.remove("China");

    ht.print();
    return 0;
}