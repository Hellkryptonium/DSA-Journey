#include <iostream>
#include <vector>
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

Node *buildBSTfromSorted(int arr[], int st, int end)
{
    if (st > end)
    {
        return nullptr;
    }
    int mid = st + (end - st) / 2;
    Node *curr = new Node(arr[mid]);
    curr->left = buildBSTfromSorted(arr, st, mid - 1);
    curr->right = buildBSTfromSorted(arr, mid + 1, end);

    return curr;
}

void preorder(Node *root)
{
    if (root == nullptr)
    {
        return;
    }

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
Node *buildBSTfromSortedVec(vector<int> arr, int st, int end)
{
    if (st > end)
    {
        return nullptr;
    }
    int mid = st + (end - st) / 2;
    Node *curr = new Node(arr[mid]);
    curr->left = buildBSTfromSortedVec(arr, st, mid - 1);
    curr->right = buildBSTfromSortedVec(arr, mid + 1, end);

    return curr;
}
void getInorder(Node *root, vector<int> &nodes)
{
    if (root == nullptr)
    {
        return;
    }

    getInorder(root->left, nodes);
    nodes.push_back(root->data);
    getInorder(root->right, nodes);
}

Node *balanceBST(Node *root)
{
    // get inroder seq
    vector<int> nodes;
    getInorder(root, nodes);

    return buildBSTfromSortedVec(nodes, 0, nodes.size() - 1);
}

int main()
{
    Node *root = new Node(6);
    root->left = new Node(5);
    root->left->left = new Node(4);
    root->left->left->left = new Node(3);

    root->right = new Node(7);
    root->right->right = new Node(8);
    root->right->right->right = new Node(9);

    root = balanceBST(root);

    preorder(root);

    return 0;
}