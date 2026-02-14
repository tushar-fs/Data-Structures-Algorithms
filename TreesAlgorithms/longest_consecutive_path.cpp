/**
 * Problem: Longest Consecutive Sequence in Binary Tree (LC #298)
 * Find the longest path of consecutive values (each child = parent + 1)
 * in a binary tree from parent to child.
 * Time Complexity: O(n)
 * Space Complexity: O(h) — recursion stack
 */
#include <iostream>
#include "include/BinaryTreeNode.h"

using namespace std;
int ans = 0;

int longestConsecutivePath(TreeNode *root)
{
    if (root == nullptr)
        return 0;

    int leftSubRes = longestConsecutivePath(root->left);
    int rightSubRes = longestConsecutivePath(root->right);

    int pathStartingHere = 1;
    if (root->left && root->val == root->left->val - 1)
    {
        pathStartingHere = max(pathStartingHere, 1 + leftSubRes);
    }

    if (root->right && root->val == root->right->val - 1)
    {
        pathStartingHere = max(pathStartingHere, 1 + rightSubRes);
    }

    ans = max(ans, pathStartingHere);
    return pathStartingHere;
}