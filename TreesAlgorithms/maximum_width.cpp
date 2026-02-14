/**
 * Problem: Maximum Width of Binary Tree (LC #662)
 * Given a binary tree, find the maximum width among all levels. The width of a
 * level is the number of positions between the leftmost and rightmost non-null nodes.
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */
#include <iostream>
#include "include/BinaryTreeNode.h";

using namespace std;

int maxWidthOfBinaryTree(TreeNode *root)
{
    if (root == nullptr)
        return 0;
    int maxWidth = 0;
    queue<pair<TreeNode *, int>> q;
    q.push({root, 0}); // 0-based indexing
    while (!q.empty())
    {
        int sz = q.size();
        int leftMostPos = q.front().second;
        int rightMostPos = leftMostPos;
        for (int i = 0; i < sz; i++)
        {
            TreeNode *cur = q.front().first;
            int curPos = q.front().second;
            rightMostPos = max(rightMostPos, curPos);
            q.pop();
            if (cur->left)
                q.push({cur->left, 2 * curPos + 1});
            if (cur->right)
                q.push({cur->right, 2 * curPos + 2});
        }
        maxWidth = max(maxWidth, rightMostPos - leftMostPos + 1);
    }
    return maxWidth;
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