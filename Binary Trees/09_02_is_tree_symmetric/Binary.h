#include <iostream>

template <typename T>
struct BinaryTreeNode {
    T data;
    BinaryTreeNode<T>* left, *right;
};

template <typename T>
void insert(BinaryTreeNode<T>*& root, T data) {
    if (root == nullptr) {
        root = new BinaryTreeNode<T>{data, nullptr, nullptr};
    }
    else {
        if (data < root->data) {
            insert(root->left, data);
        }
        else {
            insert(root->right, data);
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

