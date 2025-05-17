#include <iostream>
#include <map>
#include "include/BinaryTreeNode.h";

using namespace std;

void dfsLeftView(TreeNode *root, vector<int> &leftView, int depth, int &maxDepth)
{
    if (root == nullptr)
        return;
    if (depth > maxDepth)
    {
        leftView.push_back(root->val);
        maxDepth = depth;
    }
    dfsLeftView(root->left, leftView, depth + 1, maxDepth);
    dfsLeftView(root->right, leftView, depth + 1, maxDepth);
}

// Approach 2: Using BFS

int main()
{
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(3); // Adding a couple more nodes for better traversal examples
    root->left->right = new TreeNode(7);
    root->right->right = new TreeNode(18);

    vector<int> leftView;
    int maxDepth = 0;
    dfsLeftView(root, leftView, 0, maxDepth);
    for (int x : leftView)
        cout << x << " ";

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