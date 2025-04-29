#include <iostream>
#include <queue>
#include <stack>
#include "include/BinaryTreeNode.h"

using namespace std;

/**
 * Inorder -> [left, root, right]
 */
void traverseInorder(TreeNode *root)
{
    if (root == nullptr)
        return;
    traverseInorder(root->left);
    cout << root->val << " ";
    traverseInorder(root->right);
}

/**
 * Preorder -> [root, left, right]
 */
void traversePreorder(TreeNode *root)
{
    if (root == nullptr)
        return;
    cout << root->val << " ";
    traversePreorder(root->left);
    traversePreorder(root->right);
}

void traversePreorderIterative(TreeNode *root)
{
    if (root == nullptr)
        return;

    stack<TreeNode *> st;
    cout << root->val << " ";
    st.push(root);
    while (!st.empty())
    {
        while (root->left)
        {
            cout << root->left->val << " ";
            st.push(root->left);
        }
        while (!st.empty())
        {
        }
    }
}

/**
 * Postorder -> [left, right, root]
 */
void traversePostorder(TreeNode *root)
{
    if (root == nullptr)
        return;
    traversePostorder(root->left);
    traversePostorder(root->right);
    cout << root->val << " ";
}

/*
 * Level order BFS
 */

void bfs(TreeNode *root)
{
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode *curNode = q.front();
        q.pop();
        cout << curNode->val << " ";
        if (curNode->left)
            q.push(curNode->left);
        if (curNode->right)
            q.push(curNode->right);
    }
}

int main()
{
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(3); // Adding a couple more nodes for better traversal examples
    root->left->right = new TreeNode(7);
    root->right->right = new TreeNode(18);

    std::cout << "Tree traversals:" << std::endl;

    std::cout << "Inorder: ";
    traverseInorder(root);
    std::cout << std::endl;

    std::cout << "Preorder: ";
    traversePreorder(root); // Call the corrected preorder
    std::cout << std::endl;

    std::cout << "Postorder: ";
    traversePostorder(root); // Call the corrected postorder
    std::cout << std::endl;

    std::cout << "BFS (Level Order): ";
    bfs(root);
    std::cout << std::endl;

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