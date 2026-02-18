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

void KthHelper(Node *root, int k, int currLevel)
{
    if (root == nullptr)
    {
        return;
    }

    if (currLevel == k)
    {
        cout << root->data << " ";
        return;
    }

    KthHelper(root->left, k, currLevel + 1);
    KthHelper(root->right, k, currLevel + 1);
}

void KthLevel(Node *root, int k) // O(n)
{
    KthHelper(root, k, 1);
    cout << endl;
}

bool rootToNodePath(Node *root, int n, vector<int> &path)
{
    if (root == nullptr)
    {
        return false;
    }

    path.push_back(root->data);
    if (root->data == n)
    {
        return true;
    }

    bool isLeft = rootToNodePath(root->left, n, path);
    bool isRight = rootToNodePath(root->right, n, path);

    if (isLeft || isRight)
    {
        return true;
    }

    path.pop_back();
    return false;
}

int LCA(Node *root, int n1, int n2)
{
    vector<int> path1;
    vector<int> path2;

    rootToNodePath(root, n1, path1);
    rootToNodePath(root, n2, path2);
    int lca = -1;
    for (int i = 0, j = 0; i < path1.size() && j < path2.size(); i++, j++)
    {
        if (path1[i] != path2[j])
        {
            return lca;
        }
        lca = path1[i];
    }
    return lca;
}

Node *LCA2(Node *root, int n1, int n2)
{
    if (root == nullptr)
    {
        return nullptr;
    }

    if (root->data == n1 || root->data == n2)
    {
        return root;
    }

    Node *leftLCA = LCA2(root->left, n1, n2);
    Node *rightLCA = LCA2(root->right, n1, n2);

    if (leftLCA != nullptr && rightLCA != nullptr)
    {
        return root;
    }

    return leftLCA == nullptr ? rightLCA : leftLCA;
}

int dist(Node *root, int n)
{
    if (root == nullptr)
    {
        return -1;
    }

    if (root->data == n)
    {
        return 0;
    }

    int leftDist = dist(root->left, n);
    if (leftDist != -1)
    {
        return leftDist + 1;
    }

    int rightDist = dist(root->right, n);
    if (rightDist != -1)
    {
        return rightDist + 1;
    }

    return -1;
}

int minDist(Node *root, int n1, int n2)
{
    Node *lca = LCA2(root, n1, n2);

    int dist1 = dist(lca, n1);
    int dist2 = dist(lca, n2);

    return dist1 + dist2;
}

int KthAncestor(Node *root, int node, int K)
{
    if (root == nullptr)
    {
        return -1;
    }

    if (root->data == node)
    {
        return 0;
    }

    int leftDist = KthAncestor(root->left, node, K);
    int rightDist = KthAncestor(root->right, node, K);

    if (leftDist == -1 && rightDist == -1)
    {
        return -1;
    }

    int validVal = leftDist == -1 ? rightDist : leftDist;
    if (validVal + 1 == K)
    {
        cout << "Kth Ancestor : " << root->data << endl;
    }

    return validVal + 1;
}

int transform(Node *root)
{
    if (root == nullptr)
    {
        return 0;
    }

    int leftOld = transform(root->left);
    int rightOld = transform(root->right);
    int currOld = root->data;

    root->data = leftOld + rightOld;

    if (root->left != nullptr)
    {
        root->data += root->left->data;
    }

    if (root->right != nullptr)
    {
        root->data += root->right->data;
    }

    return currOld;
}

int main()
{
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    Node *root = buildTree(nodes);

    return 0;
}