#include <iostream>
#include <BinaryTreeNode.h>

using namespace std;

void sinkIsland(TreeNode *root)
{
    if (root == nullptr || root->val == 0)
        return;

    root->val = 0;
    sinkIsland(root->left);
    sinkIsland(root->right);
}

int countIslands(TreeNode *root, int &count)
{
    if (root == nullptr)
        return;

    if (root->val == 1)
    {
        count++;
        sinkIsland(root);
    }

    countIslands(root->left, count);
    countIslands(root->right, count);
}
