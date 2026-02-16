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

pair<int, int> diam2(Node *root)
{
    if (root == nullptr)
    {
        return make_pair(0, 0);
    }

    //(diameter, height)
    pair<int, int> leftInfo = diam2(root->left);   //(LD, LH)
    pair<int, int> rightInfo = diam2(root->right); //(RD, RH)

    int currDiam = leftInfo.second + rightInfo.second + 1;
    int finalDiam = max(currDiam, max(leftInfo.first, rightInfo.first));
    int finalHt = max(leftInfo.second, rightInfo.second) + 1;

    return make_pair(finalDiam, finalHt);
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

int diam1(Node *root)
{
    if (root == nullptr)
        return 0;

    int currDiam = height(root->left) + height(root->right) + 1;
    int leftDiam = diam1(root->left);
    int rightDiam = diam1(root->right);

    return max(currDiam, max(leftDiam, rightDiam));
}

int sum(Node *root)
{
    if (root == nullptr)
        return 0;

    int leftSum = sum(root->left);
    int rightSum = sum(root->right);

    return leftSum + rightSum + root->data;
}

bool isIdentical(Node *root1, Node *root2)
{
    if (root1 == nullptr && root2 == nullptr)
    {
        return true;
    }
    else if (root1 == nullptr || root2 == nullptr)
    {
        return false;
    }
    if (root1->data != root2->data)
    {
        return false;
    }

    return isIdentical(root1->left, root2->left) &&
           isIdentical(root1->right, root2->right);
}

bool isSubtree(Node *root, Node *subRoot)
{
    if (root == nullptr && subRoot == nullptr)
    {
        return true;
    }
    else if (root == nullptr || subRoot == nullptr)
    {
        return false;
    }
    if (root->data == subRoot->data)
    {
        if (isIdentical(root, subRoot))
        {
            return true;
        }
    }

    bool isLeftSubtree = isSubtree(root->left, subRoot);
    if (!isLeftSubtree)
    {
        return isSubtree(root->right, subRoot);
    }

    return true;
}

void topView(Node *root)
{
    queue<pair<Node *, int>> Q; //(node, HD)
    map<int, int> m;            //(HD, node->data)

    Q.push(make_pair(root, 0));

    while (!Q.empty())
    {
        pair<Node *, int> curr = Q.front();
        Q.pop();
        Node *currNode = curr.first;
        int currHD = curr.second;

        if (m.count(currHD) == 0)
        { // HD is unique -> add in map
            m[currHD] = currNode->data;
        }

        if (currNode->left != nullptr)
        {
            pair<Node *, int> left = make_pair(currNode->left, currHD - 1);
            Q.push(left);
        }

        if (currNode->right != nullptr)
        {
            pair<Node *, int> right = make_pair(currNode->right, currHD + 1);
            Q.push(right);
        }
    }

    for (auto it : m)
    {
        cout << it.second << " ";
    }

    cout << endl;
}

int main()
{
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    Node *root = buildTree(nodes);

    topView(root);
    return 0;
}