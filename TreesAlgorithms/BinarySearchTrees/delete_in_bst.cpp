/**
 * Problem: Delete Node in a BST (LC #450)
 * Given a root of BST and a key, delete the node with the given key.
 * Handles three cases: leaf node, one child, and two children (inorder successor).
 * Time Complexity: O(h)
 * Space Complexity: O(h) — recursion stack
 */
#include "../include/BinaryTreeNode.h"

TreeNode *deleteNode(TreeNode *root, int key)
{
    if (root == nullptr)
        return nullptr;

    if (root->val < key)
    {
        root->left = deleteNode(root->left, key);
    }
    else if (root->val > key)
    {
        root->right = deleteNode(root->right, key);
    }
    else
    {
        if (root->left == nullptr)
        {
            TreeNode *temp = root->right;
            delete root;
            return temp;
        }

        if (root->right == nullptr)
        {
            TreeNode *temp = root->left;
            delete root;
            return temp;
        }

        // find min in right subtree
        TreeNode *temp = root->right;
        while (temp->left)
        {
            temp = temp->left;
        }
        root->val = temp->val;
        root->right = deleteNode(root->right, temp->val);
        return root->right;
    }
    return root;
}