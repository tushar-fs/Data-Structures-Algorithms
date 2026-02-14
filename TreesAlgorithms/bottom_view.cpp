/**
 * Problem: Bottom View of Binary Tree
 * Given a binary tree, return the nodes visible when the tree is viewed from
 * the bottom. Uses DFS with horizontal distance and depth tracking.
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */
#include <iostream>
#include <map>
#include "include/BinaryTreeNode.h";

using namespace std;

void dfs(TreeNode *root, int hd, int depth, map<int, pair<int, int>> &mp)
{
    if (root == nullptr)
        return;
    if (mp.find(hd) == mp.end())
        mp[hd] = {root->val, depth};
    else
    {
        int prevDepth = mp[hd].second;
        if (prevDepth < depth)
            mp[hd] = {root->val, depth};
    }
    dfs(root->right, hd + 1, depth + 1, mp);
    dfs(root->left, hd - 1, depth + 1, mp);
}

int main()
{
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(3); // Adding a couple more nodes for better traversal examples
    root->left->right = new TreeNode(7);
    root->right->right = new TreeNode(18);

    map<int, pair<int, int>> mp;
    dfs(root, 0, 0, mp);
    for (auto x : mp)
        cout << x.second.first << " ";

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