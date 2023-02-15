#include "./Binary.h"
#include <iostream>

bool CheckSymmetric(const BinaryTreeNode<int>* subtree_0,
const BinaryTreeNode<int>* subtree_1) {
    if(subtree_0 == nullptr && subtree_1 ==nullptr) {
        return true;
    } else if(subtree_0 != nullptr && subtree_1 != nullptr) {
        return subtree_0 -> data == subtree_1 ->data &&
        CheckSymmetric(subtree_0->left, subtree_1->right) &&
        CheckSymmetric(subtree_0->right, subtree_1->left);
    }
    return false;
}

bool IsSymmetric(const BinaryTreeNode<int>* tree) {
    return tree == nullptr || CheckSymmetric(tree->left, tree->right);
}

int main() {
    BinaryTreeNode<int>* root = nullptr;
   root = new BinaryTreeNode<int>{6, nullptr, nullptr};
    root->left = new BinaryTreeNode<int>{2, nullptr, nullptr};
    root->right = new BinaryTreeNode<int>{2, nullptr, nullptr};
    root->left->left = new BinaryTreeNode<int>{6, nullptr, nullptr};
    root->left->right = new BinaryTreeNode<int>{4, nullptr, nullptr};
    root->right->left = new BinaryTreeNode<int>{4, nullptr, nullptr};
    root->right->right = new BinaryTreeNode<int>{6, nullptr, nullptr};
    printInorder(root);
    std::cout << std::endl;
    if(IsSymmetric(root)) {
        std::cout << "true";
    } else {
    std::cout << "false";
    }
  
    return 0;
}
