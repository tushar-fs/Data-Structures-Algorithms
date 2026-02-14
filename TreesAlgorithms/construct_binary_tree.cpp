/**
 * Problem: Construct Binary Tree from Preorder and Inorder Traversal (LC #105)
 * Given preorder and inorder traversal arrays, construct the unique binary tree.
 * A unique binary tree can be constructed from inorder + preorder OR inorder + postorder.
 * Time Complexity: O(n)
 * Space Complexity: O(n) — hashmap + recursion stack
 */
#include <iostream>
#include "include/BinaryTreeNode.h"

using namespace std;

unordered_map<int, int> map;
int preIndex = 0;
TreeNode *constructBinaryTree(int inStart, int inEnd, vector<int> &preorder)
{
    if (inStart > inEnd)
        return nullptr;
    TreeNode *root = new TreeNode(preorder[preIndex++]);
    int pos = map[root->val];
    root->left = constructBinaryTree(inStart, pos - 1, preorder);
    root->right = constructBinaryTree(pos + 1, inEnd, preorder);
    return root;
}

int main()
{
    vector<int> inorder = {40, 20, 50, 10, 60, 30};
    vector<int> preorder = {10, 20, 40, 50, 30, 60};
    for (int i = 0; i < inorder.size(); i++)
    {
        map[inorder[i]] = i;
    }

    return 0;
}