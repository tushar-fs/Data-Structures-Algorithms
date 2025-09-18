#include <iostream>
#include <vector>
#include <map>
#include "include/BinaryTreeNode.h";

using namespace std;
vector<int> pre;
vector<int> in;
vector<int> post;

vector<vector<int>> verticalTraversal(TreeNode *root)
{
    vector<vector<int>> res;
    if (root == nullptr)
        return res;
    map<int, map<int, vector<int>>> mp; // can use multiset
    queue<pair<TreeNode*, pair<int, int>>> q;
    q.push({root, {0, 0}});
    while (!q.empty())
    {
        TreeNode *node = q.front().first;
        int line = q.front().second.first;
        int level = q.front().second.second;
        q.pop();
        mp[line][level].push_back(node->val);
        if (node->left != nullptr)
            q.push({node->left, {line - 1, level + 1}});
        if (node->right != nullptr)
            q.push({node->right, {line + 1, level + 1}});
    }
    for (auto x : mp)
    {
        vector<int> v;
        for (auto y : x.second)
        {
            sort(y.second.begin(), y.second.end());
            v.insert(v.end(), y.second.begin(), y.second.end());
        }
        res.push_back(v);
    }
    return res;
}

int main()
{
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(3); // Adding a couple more nodes for better traversal examples
    root->left->right = new TreeNode(7);
    root->right->right = new TreeNode(18);

    vector<vector<int>> verticalOrder = verticalTraversal(root);

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