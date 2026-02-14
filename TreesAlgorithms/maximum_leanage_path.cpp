#include <iostream>
#include "include/BinaryTreeNode.h"

using namespace std;
int ans = 0;

int longestLineagePath(TreeNode *root)
{
    if (root == nullptr)
        return 0;

    int leftSubRes = longestLineagePath(root->left);
    int rightSubRes = longestLineagePath(root->right);

    int pathStartingHere = 1;
    if (root->left != nullptr && root->val < root->left->val)
    {
        pathStartingHere = max(pathStartingHere, 1 + leftSubRes);
    }

    if (root->right != nullptr && root->val < root->right->val)
    {
        pathStartingHere = max(pathStartingHere, 1 + rightSubRes);
    }

    ans = max(ans, pathStartingHere);
    return pathStartingHere;
}