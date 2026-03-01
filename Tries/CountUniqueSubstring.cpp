#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    unordered_map<char, Node *> children;
    bool endOfWord;

    Node()
    {
        endOfWord = false;
    }
};

class Trie
{
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }

    void insert(string key)
    {
        Node *temp = root;

        for (int i = 0; i < key.size(); i++)
        {
            if (temp->children.count(key[i]) == 0)
            {
                temp->children[key[i]] = new Node(); // insert
            }
            temp = temp->children[key[i]];
        }

        temp->endOfWord = true;
    }

    bool search(string key)
    {
        Node *temp = root;

        for (int i = 0; i < key.size(); i++)
        {
            if (temp->children.count(key[i]))
            {
                temp = temp->children[key[i]];
            }
            else
            {
                return false;
            }
        }

        return temp->endOfWord;
    }

    int countHelper(Node *root)
    {
        int ans = 0;

        for (pair<char, Node *> child : root->children)
        {
            ans += countHelper(child.second);
        }
        return ans + 1;
    }

    int countNodes()
    {
        return countHelper(root);
    }
};

int countUniqueSubstr(string str)
{
    Trie trie;
    // find suffix
    for (int i = 0; i < str.size(); i++)
    {
        string suffix = str.substr(i);
        trie.insert(suffix);
    }

    return trie.countNodes();
}

int main()
{
    string str = "abc";

    cout << countUniqueSubstr(str) << endl;

    return 0;
}