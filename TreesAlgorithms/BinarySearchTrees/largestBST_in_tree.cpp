/**
 * Problem: Largest BST Subtree (LC #333)
 * Given a binary tree, find the largest subtree that is also a valid BST.
 * Returns the number of nodes in the largest BST subtree.
 * Time Complexity: O(n)
 * Space Complexity: O(h) — recursion stack
 */
#include <vector>
#include <climits>
#include "include/BinaryTreeNode.h"

using namespace std;

vector<int> largestBST(TreeNode *root)
{
    if (root == nullptr)
    {
        return {INT_MAX, INT_MIN, 0};
    }

    vector<int> left = largestBST(root->left);
    vector<int> right = largestBST(root->right);

    // Check BST condition
    if (root->val > left[1] && root->val < right[0])
    {
        int newMin = min(left[0], root->val);
        int newMax = max(right[1], root->val);
        int countNodes = 1 + left[2] + right[2];
        return {newMin, newMax, countNodes};
    }

    // Otherwise, this node breaks the BST property.
    // Invalidate the bounds and pass up the largest BST size found so far.
    return {INT_MIN, INT_MAX, max(left[2], right[2])};
}