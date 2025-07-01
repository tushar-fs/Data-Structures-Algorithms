#include "../include/BinaryTreeNode.h"

/**
 * Find lowest common ancestor in a BST
 * TC -> O(Height)
 */

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (root == nullptr)
        return nullptr;

    TreeNode *leftLca = nullptr, *rightLca = nullptr;
    if (root->val > p->val && root->val > q->val)
    {
        leftLca = lowestCommonAncestor(root->left, p, q);
    }
    else if (root->val < p->val && root->val < q->val)
    {
        rightLca = lowestCommonAncestor(root->right, p, q);
    }
    else
        return root;
    if (leftLca == nullptr)
        return rightLca;
    return leftLca;
}

/**
 * Iterative Solution
 */
TreeNode *lcaIterative(TreeNode *root, TreeNode *p, TreeNode *q)
{
    while (root)
    {
        if (root->val > p->val && root->val > q->val)
        {
            root = root->left;
        }
        else if (root->val < p->val && root->val < q->val)
        {
            root = root->right;
        }
        else
            return root;
    }
    return nullptr;
}