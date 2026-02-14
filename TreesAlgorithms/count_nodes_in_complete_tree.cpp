/**
 * Problem: Count Complete Tree Nodes (LC #222)
 * Given the root of a complete binary tree, return the number of nodes.
 * Uses the property of complete trees to achieve better than O(n) time.
 * Time Complexity: O(log²n)
 * Space Complexity: O(log n) — recursion stack
 */
#include <iostream>
#include "include/BinaryTreeNode.h"

using namespace std;

int getLeftHeight(TreeNode *root)
{
    int lh = 0;
    while (root)
    {
        lh++;
        root = root->left;
    }
    return lh;
}

int getRightHeight(TreeNode *root)
{
    int rh = 0;
    while (root)
    {
        rh++;
        root = root->right;
    }
    return rh;
}

int countNodesInCompleteBinaryTree(TreeNode *root)
{
    if (root == nullptr)
        return 0;
    int lh = getLeftHeight(root->left);
    int rh = getRightHeight(root->right);
    if (lh == rh)
        return (1 << (lh + 1)) - 1;
    return 1 + countNodesInCompleteBinaryTree(root->left) + countNodesInCompleteBinaryTree(root->right);
}

int main()
{
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(3); // Adding a couple more nodes for better traversal examples
    root->left->right = new TreeNode(7);

    cout << countNodesInCompleteBinaryTree(root);

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