#include <iostream>
#include "include/BinaryTreeNode.h";

using namespace std;

vector<int> addLeftNodes(TreeNode *root)
{
    if (root->left == nullptr)
        return {};
    vector<int> leftNodes;
    TreeNode *curNode = root->left;
    while (curNode)
    {
        if (curNode->left || curNode->right)
        {
            leftNodes.push_back(curNode->val);
        }

        if (curNode->left)
            curNode = curNode->left;
        else
            curNode = curNode->right;
    }
    return leftNodes;
}

void addLeafNodes(TreeNode *root, vector<int> &leafNodes)
{
    if (root == nullptr)
        return;
    if (root->left == nullptr && root->right == nullptr)
        leafNodes.push_back(root->val);
    addLeafNodes(root->left, leafNodes);
    addLeafNodes(root->right, leafNodes);
}

vector<int> addRightNodes(TreeNode *root)
{
    vector<int> rightNodes;
    if (root->right == nullptr)
        return rightNodes;
    TreeNode *curNode = root->right;
    while (curNode)
    {
        if (curNode->left || curNode->right)
            rightNodes.push_back(curNode->val);

        if (curNode->right)
            curNode = curNode->right;
        else
            curNode = curNode->left;
    }
    return rightNodes;
}

void boundaryTraversal(TreeNode *root)
{
    if (root == nullptr)
        return;

    cout << root->val << " ";
    boundaryTraversal(root->left);
    boundaryTraversal(root->right);
}

int main()
{
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(3); // Adding a couple more nodes for better traversal examples
    root->left->right = new TreeNode(7);
    root->right->right = new TreeNode(18);

    boundaryTraversal(root);

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