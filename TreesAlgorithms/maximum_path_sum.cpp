/**
 * Problem: Binary Tree Maximum Path Sum (LC #124)
 * Find the maximum path sum in a binary tree. A path can start and end at any
 * node and must follow parent-child connections.
 * Time Complexity: O(n)
 * Space Complexity: O(h) — recursion stack
 */
#include <iostream>
#include "include/BinaryTreeNode.h"

using namespace std;

int getMaximumPathSum(TreeNode *root, int &maxSum) {
    if(root == nullptr) return 0;

    int leftPathSum = getMaximumPathSum(root->left, maxSum);
    int rightPathSum = getMaximumPathSum(root->right, maxSum);
    int curPathSum = root->val + leftPathSum + rightPathSum;
    maxSum = max(maxSum, curPathSum);
    return root->val + max(leftPathSum, rightPathSum);
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