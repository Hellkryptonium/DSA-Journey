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

class Info
{
public:
    bool isBST;
    int min;
    int max;
    int sz;

    Info(bool isBST, int min, int max, int sz)
    {
        this->isBST = isBST;
        this->min = min;
        this->max = max;
        this->sz = sz;
    }
};

static int maxSize;
static Node *largestRoot;

Info *largestBST(Node *root)
{
    // if(root == nullptr) {
    //     return nullptr;
    // }
    // if(root->left == nullptr && root->right == nullptr) {
    //     return new Info(true, root->data, root->data, 1);
    // }
    if (root == nullptr)
    {
        return new Info(true, INT_MAX, INT_MIN, 0);
    }

    Info *leftInfo = largestBST(root->left);
    Info *rightInfo = largestBST(root->right);

    int currMin = min(root->data, min(leftInfo->min, rightInfo->min));
    int currMax = max(root->data, max(rightInfo->max, leftInfo->max));
    int currSz = leftInfo->sz + rightInfo->sz + 1;

    if (leftInfo->isBST && rightInfo->isBST && root->data > leftInfo->max && root->data < rightInfo->min)
    {
        maxSize = max(maxSize, currSz);

        return new Info(true, currMin, currMax, currSz);
    }

    return new Info(false, currMin, currMax, currSz);
}

Node *mergedBST(Node *root1, Node *root2)
{
    vector<int> nodes1;
    vector<int> nodes2;
    vector<int> merged;

    getInorder(root1, nodes1);
    getInorder(root2, nodes2);

    int i = 0, j = 0;
    while (i < nodes1.size() && j < nodes2.size())
    {
        if (nodes1[i] < nodes2[j])
        {
            merged.push_back(nodes1[i++]);
        }
        else
        {
            merged.push_back(nodes2[j++]);
        }
    }

    while (i < nodes1.size())
    {
        merged.push_back(nodes1[i++]);
    }

    while (j < nodes2.size())
    {
        merged.push_back(nodes2[j++]);
    }

    return buildBSTfromSortedVec(merged, 0, merged.size() - 1);
}

int main()
{
    Node *root1 = new Node(2);
    root1->left = new Node(1);
    root1->right = new Node(4);

    Node *root2 = new Node(9);
    root2->left = new Node(3);
    root2->right = new Node(12);

    Node *root = mergedBST(root1, root2);
    preorder(root);
    return 0;
}