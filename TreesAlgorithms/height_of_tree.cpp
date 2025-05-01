#include <iostream>
#include "include/BinaryTreeNode.h";

using namespace std;

int heightOfBinaryTree(TreeNode *root)
{
    if (root == nullptr)
        return 0;
    int maxHeight = 0;
    maxHeight = 1 + max(heightOfBinaryTree(root->left), heightOfBinaryTree(root->right));
    return maxHeight;
}

int main()
{
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(3); // Adding a couple more nodes for better traversal examples
    root->left->right = new TreeNode(7);
    root->right->right = new TreeNode(18);

    cout << heightOfBinaryTree(root);

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