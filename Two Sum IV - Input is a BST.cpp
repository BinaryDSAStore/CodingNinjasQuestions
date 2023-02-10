#include <bits/stdc++.h>
using namespace std;

template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

void helper(BinaryTreeNode<int> *root, vector<int> &v)
{
    if (root == nullptr)
        return;

    helper(root->left, v);
    v.push_back(root->data);
    helper(root->right, v);
}

bool twoSumInBST(BinaryTreeNode<int> *root, int target)
{
    if (root == nullptr)
        return 0;

    vector<int> v;
    helper(root, v);

    int i = 0, j = v.size() - 1;
    bool ans = 0;
    while (i < j)
    {
        if (v[i] + v[j] > target)
            j--;
        else if (v[i] + v[j] < target)
            i++;
        else
        {
            ans = 1;
            break;
        }
    }
    return ans;
}