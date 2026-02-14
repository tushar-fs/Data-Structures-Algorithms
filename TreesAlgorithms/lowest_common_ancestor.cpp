/**
 * Problem: Lowest Common Ancestor of a Binary Tree (LC #236)
 * Given a binary tree and two nodes p and q, find their lowest common ancestor.
 * The LCA is the deepest node that is an ancestor of both p and q.
 * Time Complexity: O(n)
 * Space Complexity: O(h) — recursion stack
 */
#include <iostream>
#include "include/BinaryTreeNode.h";

using namespace std;

TreeNode *getLCA(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (root == nullptr)
        return root;

    if (root == p || root == q)
        return root;
    TreeNode *leftLCA = getLCA(root->left, p, q);
    TreeNode *rightLCA = getLCA(root->right, p, q);
    if (leftLCA && rightLCA)
        return root;
    return leftLCA == nullptr ? rightLCA : leftLCA;
}

int main()
{
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(3); // Adding a couple more nodes for better traversal examples
    root->left->right = new TreeNode(7);
    root->right->right = new TreeNode(18);

    // --- Memory Management ---
    // For this small, fixed tree, manually deleting the created nodes works.
    // For general tree destruction, you would need a more robust approach,
    // like a recursive delete function or using smart pointers (e.g., unique_ptr).
    delete root->left->left;
    delete root->left->right;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;
    return 0;
}