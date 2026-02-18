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

Node *insert(Node *root, int val)
{
    if (root == nullptr)
    {
        root = new Node(val);
        return root;
    }

    if (val < root->data)
    {
        root->left = insert(root->left, val);
    }
    else
    {
        root->right = insert(root->right, val);
    }

    return root;
}

Node *buildBST(int arr[], int n)
{
    Node *root = nullptr;

    for (int i = 0; i < n; i++)
    {
        root = insert(root, arr[i]);
    }

    return root;
}

void inorder(Node *root)
{
    if (root == nullptr)
    {
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

bool search(Node *root, int key)
{
    if (root == nullptr)
    {
        return false;
    }

    if (root->data == key)
    {
        return true;
    }

    if (root->data > key)
    {
        return search(root->left, key);
    }
    else
    {
        return search(root->right, key);
    }
}

Node *getInorderSuccessor(Node *root)
{
    while (root->left != nullptr)
    {
        root = root->left;
    }
    return root;
}

Node *delNode(Node *root, int val)
{
    if (root == nullptr)
    {
        return nullptr;
    }

    if (val < root->data)
    { // leftsubtree
        root->left = delNode(root->left, val);
    }
    else if (val > root->data)
    { // rightsubtree
        root->right = delNode(root->right, val);
    }
    else
    {
        // root == val
        // case1 : 0 children
        if (root->left == nullptr && root->right == nullptr)
        {
            delete root;
            return nullptr;
        }

        // case 2 : 1 child
        if (root->left == nullptr || root->right == nullptr)
        {
            return root->left == nullptr ? root->right : root->left;
        }

        // case 3 : 2 children
        Node *IS = getInorderSuccessor(root->right);
        root->data = IS->data;
        delNode(root->right, IS->data); // case 1 , case 2
        return root;
    }
    return root;
}

void printInRange(Node *root, int start, int end)
{
    if (root == nullptr)
    {
        return;
    }

    if (start <= root->data && root->data <= end)
    {
        printInRange(root->left, start, end);
        cout << root->data << " ";
        printInRange(root->right, start, end);
    }
    else if (root->data < start)
    {
        printInRange(root->right, start, end);
    }
    else
    {
        printInRange(root->left, start, end);
    }
}

void printPath(vector<int> path)
{
    cout << " path : ";
    for (int i = 0; i < path.size(); i++)
    {
        cout << path[i] << " ";
    }
    cout << endl;
}

void pathHelper(Node *root, vector<int> &path)
{

    path.push_back(root->data);

    if (root->left == nullptr && root->right == nullptr)
    {
        printPath(path);
        path.pop_back();
        return;
    }

    pathHelper(root->left, path);
    pathHelper(root->right, path);

    path.pop_back();
}

void rootToLeafPath(Node *root)
{
    vector<int> path;
    pathHelper(root, path);
}

bool validateHelper(Node *root, Node *min, Node *max)
{
    if (root == nullptr)
    {
        return true;
    }

    if (min != nullptr && root->data < min->data)
    {
        return false;
    }

    if (max != nullptr && root->data > max->data)
    {
        return false;
    }

    return validateHelper(root->left, min, root) &&
           validateHelper(root->right, root, max);
}

bool validateBST(Node *root)
{
    return validateHelper(root, nullptr, nullptr);
}

int main()
{
    int arr[6] = {5, 1, 3, 4, 2, 7};
    int arr2[9] = {8, 5, 3, 1, 4, 6, 10, 11, 14};

    Node *root = buildBST(arr2, 9);

    cout << validateBST(root) << endl;

    return 0;
}