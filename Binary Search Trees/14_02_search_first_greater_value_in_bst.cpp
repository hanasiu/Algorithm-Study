#include "searchBST.h"

BstNode<int>* FindFirstGreaterThanK(BstNode<int>* tree, int k) {
    BstNode<int>* subtree = tree, *first_so_far = nullptr;
    while(subtree) {
        if(subtree->data > k) {
            first_so_far = subtree;
            subtree = subtree->left;
        } else {
            subtree = subtree->right;
        }
    }
    return first_so_far;
}

int main() {
    // Construct the binary search tree
    BstNode<int>* root = new BstNode<int>(10);
    root->left = new BstNode<int>(5);
    root->right = new BstNode<int>(15);
    root->left->left = new BstNode<int>(3);
    root->left->right = new BstNode<int>(7);
    root->right->left = new BstNode<int>(13);
    root->right->right = new BstNode<int>(18);

    // Search for a node in the binary search tree
    BstNode<int>* node = searchBST(root, 7);
    if (node != nullptr) {
        std::cout << "Found node " << node->data << std::endl;
    } else {
        std::cout << "Node not found" << std::endl;
    }

    // Find the first node greater than k
    BstNode<int>* first_node = FindFirstGreaterThanK(root, 12);
    if (first_node != nullptr) {
        std::cout << "First node greater than 12: " << first_node->data << std::endl;
    } else {
        std::cout << "No node greater than 12" << std::endl;
    }

    // Delete the binary search tree
    delete root;

    return 0;
}