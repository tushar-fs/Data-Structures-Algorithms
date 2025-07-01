#include "../include/BinaryTreeNode.h";

using namespace std;

TreeNode *constructBSTUtil(int &i, int preorder[], int n, int upperBound)
{
    if (i >= n || preorder[i] > upperBound)
        return nullptr;

    TreeNode *root = new TreeNode(preorder[i++]);
    root->left = constructBSTUtil(i, preorder, n, root->val);
    root->right = constructBSTUtil(i, preorder, n, root->val);
    return root;
}

TreeNode *constructBST(int preorder[], int n)
{
    int i = 0;
    return constructBSTUtil(i, preorder, n, 1e9);
}