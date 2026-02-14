/**
 * Problem: Right View of Binary Tree (LC #199)
 * Given a binary tree, return the nodes visible when the tree is viewed from
 * the right side. Implemented using both DFS and BFS approaches.
 * Time Complexity: O(n)
 * Space Complexity: O(h) for DFS, O(w) for BFS
 */
#include <iostream>
#include <map>
#include "include/BinaryTreeNode.h";

using namespace std;

/**
 * Method1: Using DFS
 */
void dfsRightView(TreeNode *root, vector<int> &rightView, int depth, int &maxDepth)
{
    if (root == nullptr)
        return;
    if (depth > maxDepth)
    {
        rightView.push_back(root->val);
        maxDepth = depth;
    }
    dfsRightView(root->right, rightView, depth + 1, maxDepth);
    dfsRightView(root->left, rightView, depth + 1, maxDepth);
}

/**
 * Method2: Using BFS
 */
vector<int> rightViewOfBinaryTree(TreeNode *root)
{
    if (root == nullptr)
        return;
    vector<int> rightViewNodes;
    queue<TreeNode *> q;
    q.push(root);
    int level = 0;
    while (!q.empty())
    {
        int sz = q.size();
        for (int i = 0; i < sz; i++)
        {
            TreeNode *cur = q.front();
            q.pop();
            if (i == 0)
                rightViewNodes.push_back(cur->val);
            if (cur->right)
                q.push(cur->right);
            if (cur->left)
                q.push(cur->left);
        }
        level++;
    }
    return rightViewNodes;
}

int main()
{
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(3); // Adding a couple more nodes for better traversal examples
    root->left->right = new TreeNode(7);
    root->right->right = new TreeNode(18);

    vector<int> rightView = rightViewOfBinaryTree(root);

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