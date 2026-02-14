/**
 * Problem: Validate Binary Search Tree (LC #98)
 * Given the root of a binary tree, determine if it is a valid BST.
 * Uses inorder traversal — each node must be greater than the previous.
 * Time Complexity: O(n)
 * Space Complexity: O(h) — recursion stack
 */
#include "../include/BinaryTreeNode.h";

TreeNode *prev = nullptr;
bool isValidBST(TreeNode *root)
{
    if (root == nullptr)
        return true;

    bool ok = true;
    bool left = isValidBST(root->left);
    if (prev && prev->val >= root->val)
    {
        ok = false;
    }
    prev = root;
    bool right = isValidBST(root->right);
    return ok && left && right;
}