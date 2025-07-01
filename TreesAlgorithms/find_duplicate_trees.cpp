#include <iostream>
#include "include/BinaryTreeNode.h";

using namespace std;

string dfs(TreeNode *root, unordered_map<string, int> &hm, vector<TreeNode *> &dups)
{
    if (root == nullptr)
        return "#,";

    string fingerPrint = "";
    fingerPrint += dfs(root->left, hm, dups);
    fingerPrint += dfs(root->right, hm, dups);
    fingerPrint += to_string(root->val) + ",";

    if (hm[fingerPrint] == 1)
    {
        dups.push_back(root);
    }
    hm[fingerPrint]++;

    return fingerPrint;
}

vector<TreeNode *> findDuplicateSubtrees(TreeNode *root)
{
    // Map to store: [serialized_subtree -> count]
    unordered_map<string, int> counts;
    // Vector to store the root of each unique duplicate subtree
    vector<TreeNode *> result;

    dfs(root, counts, result);

    return result;
}