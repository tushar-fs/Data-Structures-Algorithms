#include <iostream>
#include "../include/BinaryTreeNode.h"

using namespace std;

/**
 * @brief Finds the greatest value in a BST that is smaller than or equal to the key.
 * @param root The root of the BST.
 * @param key The value to find the floor value for.
 * @return The floor value. Returns -1 if no such value exists.
 */

int floorInBST(TreeNode *root, int key)
{
    int floorVal = -1;
    while (root)
    {
        if (root->val <= key)
        {
            floorVal = root->val;
            root = root->right;
        }
        else
            root = root->left;
    }
    return floorVal;
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

    delete root->right->right;
    delete root->right->left;
    delete root->left->right;
    delete root->left->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}