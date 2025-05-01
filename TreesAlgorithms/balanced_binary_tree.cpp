#include <iostream>
#include "include/BinaryTreeNode.h"

using namespace std;

int getHeight(TreeNode *root)
{
    if (root == nullptr)
        return 0;
    return 1 + max(getHeight(root->left), getHeight(root->right));
}

bool isBalanced(TreeNode *root)
{
    if (root == nullptr)
        return true;
    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);
    return abs(leftHeight - rightHeight) <= 1 && isBalanced(root->left) && isBalanced(root->right);
}

int main()
{
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(3); // Adding a couple more nodes for better traversal examples
    root->left->right = new TreeNode(7);
    root->right->right = new TreeNode(18);

    if (isBalanced(root))
        cout << "Balanced";
    else
        cout << "Not Balanced";

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