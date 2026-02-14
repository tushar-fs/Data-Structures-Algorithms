/**
 * Problem: Evaluate Expression Tree
 * Given a binary expression tree where leaves are operands and internal nodes
 * are operators (+, -, *, /), evaluate the expression represented by the tree.
 * Time Complexity: O(n)
 * Space Complexity: O(h) — recursion stack
 */
#include <iostream>
#include "include/BinaryTreeNode.h"

using namespace std;

int stringToNum(string s)
{
    int num = 0;
    for (int i = 0; i < s.size(); i++)
    {
        num *= 10;
        num += s[i] - '0';
    }
    return num;
}

int evaluateTree(TreeNode *root)
{
    if (root == nullptr)
        return 0;
    if (root->left == nullptr && root->right == nullptr)
        return stringToNum(root->val);
    int left = evaluateTree(root->left);
    int right = evaluateTree(root->right);
    if (root->val == '+')
        return left + right;
    if (root->val == '-')
        return left - right;
    if (root->val == '*')
        return left * right;
    if (root->val == '/')
        return left / right;
}