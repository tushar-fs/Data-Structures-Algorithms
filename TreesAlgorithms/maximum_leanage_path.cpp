/**
 * Problem: Longest Increasing Path in Binary Tree (Lineage Path)
 * Find the longest path in a binary tree where each node's value is strictly
 * less than its child's value (strictly increasing from parent to child).
 * Time Complexity: O(n)
 * Space Complexity: O(h) — recursion stack
 */
#include <iostream>
#include "include/BinaryTreeNode.h"

using namespace std;
int ans = 0;

int longestLineagePath(TreeNode *root)
{
    if (root == nullptr)
        return 0;

    int leftSubRes = longestLineagePath(root->left);
    int rightSubRes = longestLineagePath(root->right);

    int pathStartingHere = 1;
    if (root->left != nullptr && root->val < root->left->val)
    {
        pathStartingHere = max(pathStartingHere, 1 + leftSubRes);
    }

    if (root->right != nullptr && root->val < root->right->val)
    {
        pathStartingHere = max(pathStartingHere, 1 + rightSubRes);
    }

    ans = max(ans, pathStartingHere);
    return pathStartingHere;
}