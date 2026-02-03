#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        left = right = nullptr;
    }
};

static int idx = -1;

Node *buildTree(vector<int> &nodes)
{
    idx++;
    if (nodes[idx] == -1)
    {
        return nullptr;
    }

    Node *currNode = new Node(nodes[idx]);
    currNode->left = buildTree(nodes);
    currNode->right = buildTree(nodes);

    return currNode;
}

void preorder(Node *root)
{
    if (root == nullptr)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node *root)
{
    if (root == nullptr)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

void levelOrder(Node *root)
{
    if (root == nullptr)
        return;
    queue<Node *> q;
    q.push(root);
    q.push(nullptr);

    while (!q.empty())
    {
        Node *curr = q.front();
        q.pop();
        if (curr == nullptr)
        {
            cout << endl;
            if (q.empty())
            {
                break;
            }
            q.push(nullptr);
        }
        else
        {

            cout << curr->data << " ";

            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }
    }
}

int height(Node *root)
{
    if (root == nullptr)
        return 0;

    int leftHt = height(root->left);
    int rightHt = height(root->right);

    int currHt = max(leftHt, rightHt) + 1;
    return currHt;
}

int count(Node *root)
{
    if (root == nullptr)
    {
        return 0;
    }

    return count(root->left) + count(root->right) + 1;
}

int sum(Node *root)
{
    if (root == nullptr)
        return 0;

    int leftSum = sum(root->left);
    int rightSum = sum(root->right);

    return leftSum + rightSum + root->data;
}
int main()
{
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};

    Node *root = buildTree(nodes);

    cout << sum(root);
    return 0;
}