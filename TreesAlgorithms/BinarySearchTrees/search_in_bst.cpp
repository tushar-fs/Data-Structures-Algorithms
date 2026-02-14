/**
 * Problem: Search in a Binary Search Tree (LC #700)
 * Given the root of a BST and a target value, find the node with that value.
 * Iterative approach leveraging BST property.
 * Time Complexity: O(h)
 * Space Complexity: O(1)
 */
#include <iostream>
#include "../include/BinaryTreeNode.h"

using namespace std;

bool searchInBST(TreeNode *root, int target)
{
    while (root)
    {
        if (root->val == target)
            return true;
        else if (root->val < target)
            root = root->right;
        else
            root = root->left;
    }
    return false;
}

int main()
{
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(6);
    root->right->left = new TreeNode(12);
    root->right->right = new TreeNode(20);
    if (searchInBST(root, 19))
        cout << "found";
    else
        cout << "Not found";
    return 0;
}