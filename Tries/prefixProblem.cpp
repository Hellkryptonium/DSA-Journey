#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    unordered_map<char, Node *> children;
    bool endOfWord;
    int freq;

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
        root->freq = -1;
    }

    void insert(string key)
    {
        Node *temp = root;

        for (int i = 0; i < key.size(); i++)
        {
            if (temp->children.count(key[i]) == 0)
            {
                temp->children[key[i]] = new Node(); // insert
                temp->children[key[i]]->freq = 1;
            }
            else
            {
                temp->children[key[i]]->freq++;
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

    string getPrefix(string key)
    {
        Node *temp = root;
        string prefix = "";

        for (int i = 0; i < key.size(); i++)
        {
            prefix += key[i];
            if (temp->children[key[i]]->freq == 1)
            {
                return prefix;
            }
            temp = temp->children[key[i]];
        }

        return prefix;
    }

    // start with function

    bool startsWith(string prefix)
    {
        Node *temp = root;

        for (int i = 0; i < prefix.size(); i++)
        {
            if (temp->children[prefix[i]])
            {
                temp = temp->children[prefix[i]];
            }
            else
            {
                return false;
            }
        }

        return true;
    }
};

void prefixProblem(vector<string> dict)
{
    Trie trie;
    for (int i = 0; i < dict.size(); i++)
    {
        trie.insert(dict[i]);
    }

    for (int i = 0; i < dict.size(); i++)
    {
        cout << trie.getPrefix(dict[i]) << endl;
    }
}

int main()
{
    Trie trie;
    vector<string> words = {"apple", "app", "mango", "man", "woman"};

    for (int i = 0; i < words.size(); i++)
    {
        trie.insert(words[i]);
    }

    cout << trie.startsWith("amop") << endl;

    return 0;
}