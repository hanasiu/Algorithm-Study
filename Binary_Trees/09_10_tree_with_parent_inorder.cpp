#include <iostream>
#include <vector>
#include "RawBinaryTree.h"

using namespace std;

vector<int> InorderTraversal(BinaryTreeNode<int> *tree)
{
    BinaryTreeNode<int> *prev = nullptr, *curr = tree;
    vector<int> result;

    while (curr != nullptr)
    {
        BinaryTreeNode<int> *next;
        if (curr->parent == prev)
        {
            if (curr->left != nullptr)
            {
                next = curr->left;
            }
            else
            {
                result.emplace_back(curr->data);
                next = (curr->right != nullptr) ? curr->right : curr->parent;
            }
        }
        else if (curr->left == prev)
        {
            result.emplace_back(curr->data);
            next = (curr->right != nullptr) ? curr->right : curr->parent;
        }
        else
        {
            next = curr->parent;
        }

        prev = curr;
        curr = next;
    }
    return result;
}

int main()
{
    // create a binary tree
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(1);
    root->parent = nullptr;  // set the parent pointer to nullptr
    root->left = new BinaryTreeNode<int>(2);
    root->left->parent = root;
    root->right = new BinaryTreeNode<int>(3);
    root->right->parent = root;
    root->left->left = new BinaryTreeNode<int>(4);
    root->left->left->parent = root->left;
    root->left->right = new BinaryTreeNode<int>(5);
    root->left->right->parent = root->left;
    root->right->left = new BinaryTreeNode<int>(6);
    root->right->left->parent = root->right;
    root->right->right = new BinaryTreeNode<int>(7);
    root->right->right->parent = root->right;

    // call InorderTraversal and print the result
    vector<int> result = InorderTraversal(root);
    for (int i : result)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}






