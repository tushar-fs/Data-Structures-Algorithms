#include "../include/BinaryTreeNode.h";

TreeNode *prev = nullptr;
bool isValidBST(TreeNode *root)
{
    if (root == nullptr)
        return true;

    bool ok = true;
    bool left = isValidBST(root->left);
    if (prev && prev->val >= root->val)
    {
        ok = false;
    }
    prev = root;
    bool right = isValidBST(root->right);
    return ok && left && right;
}