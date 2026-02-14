/**
 * Problem: Top View of Binary Tree
 * Given a binary tree, return the nodes visible when the tree is viewed from
 * the top. Uses BFS with horizontal distance tracking.
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */
#include <iostream>
#include "include/BinaryTreeNode.h";

using namespace std;

void printTopView(TreeNode *root)
{
    if (root == nullptr)
        return;
    unordered_map<int, int> hm;
    queue<pair<TreeNode *, pair<int, int>>> q;
    int minHd = INT_MAX;
    // q -> {node, {horizontal dist from root, level}}
    q.push({root, {0, 0}});
    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            TreeNode *curNode = q.front().first;
            pair<int, int> pos = q.front().second;
            q.pop();
            int hd = pos.first;
            int level = pos.second;
            if (hm.count(hd) == 0)
                hm[hd] = curNode->val;
            minHd = min(minHd, hd);
            if (curNode->left)
                q.push({curNode->left, {hd - 1, level + 1}});
            if (curNode->right)
                q.push({curNode->right, {hd + 1, level + 1}});
        }
    }

    vector<int> topView(hm.size());
    for (auto x : hm)
    {
        topView[x.first - minHd] = x.second;
    }
    for (int x : topView)
        cout << x << " ";
}

int main()
{
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(3); // Adding a couple more nodes for better traversal examples
    root->left->right = new TreeNode(7);
    root->right->right = new TreeNode(18);

    printTopView(root);

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