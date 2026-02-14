/**
 * Problem: Count Connected Components (Number of Islands)
 * Given a binary tree with 0s and 1s, count the number of connected components
 * (islands) of 1s. Uses DFS to "sink" visited islands.
 * Time Complexity: O(n)
 * Space Complexity: O(h) — recursion stack
 */
#include <iostream>
#include <BinaryTreeNode.h>

using namespace std;

void sinkIsland(TreeNode *root)
{
    if (root == nullptr || root->val == 0)
        return;

    root->val = 0;
    sinkIsland(root->left);
    sinkIsland(root->right);
}

int countIslands(TreeNode *root, int &count)
{
    if (root == nullptr)
        return;

    if (root->val == 1)
    {
        count++;
        sinkIsland(root);
    }

    countIslands(root->left, count);
    countIslands(root->right, count);
}
