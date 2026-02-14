#include <iostream>
#include "include/BinaryTreeNode.h"

using namespace std;
int ans = 0;

int longestUnivaluePath(TreeNode *root)
{
    if (root == nullptr)
        return 0;

    int leftSubRes = longestUnivaluePath(root->left);
    int rightSubRes = longestUnivaluePath(root->right);

    int leftPath = 0, rightPath = 0;
    if (root->left && root->val == root->left->val)
    {
        leftPath = 1 + leftSubRes;
    }

    if (root->right && root->val == root->right->val)
    {
        rightPath = 1 + rightSubRes;
    }

    ans = max(ans, leftPath + rightPath);
    return max(leftPath, rightPath);
}