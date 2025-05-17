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

void traverseIterativeInorder(TreeNode *root)
{
    if (root == nullptr)
        return;

    stack<TreeNode *> st;
    st.push(root);
    root = root->left;
    while (!st.empty() || root != nullptr)
    {
        while (root != nullptr)
        {
            st.push(root);
            root = root->left;
        }
        root = st.top();
        st.pop();
        cout << root->val << " ";
        root = root->right;
    }
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

    cout << root->val << " ";
    stack<TreeNode *> st;
    st.push(root);
    TreeNode *curNode = root->left;
    while (!st.empty() || curNode != nullptr)
    {
        while (curNode != nullptr)
        {
            cout << curNode->val << " ";
            st.push(curNode);
            curNode = curNode->left;
        }
        curNode = st.top();
        st.pop();
        curNode = curNode->right;
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

void iterativePostorder(TreeNode *root)
{
    if (root == nullptr)
        return;

    stack<TreeNode *> st1, st2;
    st1.push(root);
    while (!st1.empty())
    {
        TreeNode *curNode = st1.top();
        st1.pop();
        if (curNode->left)
            st1.push(curNode->left);
        if (curNode->right)
            st1.push(curNode->right);
        st2.push(curNode);
    }

    while (!st2.empty())
    {
        TreeNode *temp = st2.top();
        cout << temp->val << " ";
        st2.pop();
    }
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
    cout << "\n";
    traverseIterativeInorder(root);
    std::cout << std::endl;

    std::cout << "Preorder: ";
    traversePreorder(root); // Call the corrected preorder
    cout << "\n";
    traversePreorderIterative(root);
    std::cout << std::endl;

    std::cout << "Postorder: ";
    traversePostorder(root); // Call the corrected postorder
    cout<<"\n";
    iterativePostorder(root);
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