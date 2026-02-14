/**
 * Problem: Insert into a Binary Search Tree (LC #701)
 * Given the root of a BST and a value to insert, place the new node in the
 * correct position to maintain BST properties.
 * Time Complexity: O(h)
 * Space Complexity: O(1)
 */
#include <iostream>
#include "../include/BinaryTreeNode.h"

using namespace std;

TreeNode *insertInBST(TreeNode *root, int key)
{
    if (root == nullptr)
        return new TreeNode(key);

    TreeNode *cur = root;
    TreeNode *lastNode = nullptr;
    while (cur)
    {
        lastNode = cur;
        if (cur->val <= key)
            cur = cur->right;
        else
            cur = cur->left;
    }

    if (lastNode->val <= key)
        lastNode->right = new TreeNode(key);
    else
        lastNode->left = new TreeNode(key);
    return root;
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

    return 0;
}