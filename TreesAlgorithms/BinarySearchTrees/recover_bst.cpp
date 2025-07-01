#include "../include/BinaryTreeNode.h";

using namespace std;

TreeNode *first = nullptr;
TreeNode *second = nullptr;
TreeNode *third = nullptr;
TreeNode *prev = nullptr;

void recoverBSTUtil(TreeNode *root, int &count)
{
    if (root == nullptr)
        return;

    recoverBSTUtil(root->left, count);
    if (root->val < prev->val)
    {
        count++;
        if (count == 1)
        {
            first = prev;
            second = root;
        }
        else if (count == 2)
        {
            third = root;
        }
    }
    prev = root;
    recoverBSTUtil(root->right, count);
}

TreeNode *recoverBST(TreeNode *root)
{
    int count = 0;
    recoverBSTUtil(root, count);
    if (count == 1)
    {
        int temp = first->val;
        first->val = second->val;
        second->val = temp;
    }
    else
    {
        int temp = first->val;
        first->val = third->val;
        third->val = temp;
    }
    return root;
}