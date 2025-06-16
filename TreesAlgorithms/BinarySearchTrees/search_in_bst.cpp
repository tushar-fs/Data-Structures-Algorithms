#include <iostream>
#include "../include/BinaryTreeNode.h"

using namespace std;

bool searchInBST(TreeNode *root, int target)
{
    while (root)
    {
        if (root->val == target)
            return true;
        else if (root->val < target)
            root = root->right;
        else
            root = root->left;
    }
    return false;
}

int main()
{
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(6);
    root->right->left = new TreeNode(12);
    root->right->right = new TreeNode(20);
    if (searchInBST(root, 19))
        cout << "found";
    else
        cout << "Not found";
    return 0;
}