/**
 * Problem: Binary Tree DFS Traversals (Pre, In, Post) — Single Pass
 * Perform all three DFS traversals (preorder, inorder, postorder) in a
 * single recursive pass through the binary tree.
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */
#include <iostream>
#include "include/BinaryTreeNode.h";

using namespace std;
vector<int> pre;
vector<int> in;
vector<int> post;

void dfsTraversal(TreeNode *root)
{
    if (root == nullptr)
        return;
    pre.push_back(root->val);
    dfsTraversal(root->left);
    in.push_back(root->val);
    dfsTraversal(root->right);
    post.push_back(root->val);
}

int main()
{
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(3); // Adding a couple more nodes for better traversal examples
    root->left->right = new TreeNode(7);
    root->right->right = new TreeNode(18);

    dfsTraversal(root);

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