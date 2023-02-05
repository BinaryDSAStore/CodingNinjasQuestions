#include <bits/stdc++.h>
using namespace std;

template <typename T>
class TreeNode
{
public:
    T val;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};

int floorInBST(TreeNode<int> *root, int X)
{
    if (!root)
        return INT_MAX;

    if (root->val == X)
        return root->val;

    if (root->val > X)
        return floorInBST(root->left, X);

    int floorValue = floorInBST(root->right, X);
    return (floorValue <= X) ? floorValue : root->val;
}