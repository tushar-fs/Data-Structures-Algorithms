/**
 * Problem: Invert Binary Tree (LC #226)
 * Given the root of a binary tree, invert (mirror) the tree by swapping
 * every left child with its corresponding right child.
 * Time Complexity: O(n)
 * Space Complexity: O(h) — recursion stack
 */
#include "include/BinaryTreeNode.h"

using namespace std;

TreeNode *invertTree(TreeNode *root)
{
    if (root == nullptr)
        return root;

    TreeNode *leftTemp = root->left;
    root->left = invertTree(root->right);
    root->right = invertTree(leftTemp);
    return root;
}