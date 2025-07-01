#include "include/BinaryTreeNode.h"

using namespace std;

TreeNode *invertTree(TreeNode *root)
{
    if (root == nullptr)
        return root;

    TreeNode *leftTemp = root->left;
    root->left = invertTree(root->right);
    root->right = invertTree(leftTemp);
    return root;
}