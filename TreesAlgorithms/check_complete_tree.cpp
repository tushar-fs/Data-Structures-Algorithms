#include <iostream>
#include "include/BinaryTreeNode.h"

using namespace std;

bool isCompleteTree(TreeNode *root)
{
    if (root == nullptr)
        return true;

    queue<TreeNode *> q;
    bool found_null = false;
    q.push(root);
    while (!q.empty())
    {
        TreeNode *cur = q.front();
        q.pop();
        if (cur == nullptr)
            found_null = true;
        else
        {
            if (found_null)
                return false;
            q.push(cur->left);
            q.push(cur->right);
        }
    }
    return true;
}

int main()
{
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(3); // Adding a couple more nodes for better traversal examples
    root->left->right = new TreeNode(7);
    root->right->right = new TreeNode(18);

    cout << isCompleteTree(root);
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