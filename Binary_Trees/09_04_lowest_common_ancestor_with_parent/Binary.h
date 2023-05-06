#include <iostream>

template <typename T>
struct BinaryTreeNode {
    T data;
    BinaryTreeNode<T>* left, *right;
    BinaryTreeNode<T>* parent;
};

template <typename T>
void insert(BinaryTreeNode<T>*& root, T data, BinaryTreeNode<T>* parent = nullptr) {
    if (root == nullptr) {
        root = new BinaryTreeNode<T>{data, nullptr, nullptr, parent};
    }
    else {
        if (data < root->data) {
            insert(root->left, data, root);
        }
        else {
            insert(root->right, data, root);
        }
    }
}

template <typename T>
void printInorder(BinaryTreeNode<T>* root) {
    if (root == nullptr) {
        return;
    }
    printInorder(root->left);
    std::cout << root->data << " ";
    printInorder(root->right);
}