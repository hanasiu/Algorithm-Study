#include "searchBST.h"
#include <iostream>

void FindKLargestInBSTHelper(const BstNode<int>* tree, int k, 
vector<int>* k_largest_elements) {
    if(tree && (*k_largest_elements).size()< k) {
        FindKLargestInBSTHelper(tree->right, k, k_largest_elements);
        if((*k_largest_elements).size() < k) {
            k_largest_elements->emplace_back(tree->data);
            FindKLargestInBSTHelper(tree->left, k, k_largest_elements);
        }
    }   
}

vector<int> FindKLargestInBST(const BstNode<int>* tree, int k) {
    vector<int> k_largest_elements;
    FindKLargestInBSTHelper(tree, k, &k_largest_elements);
    return k_largest_elements;
}

int main() {
    // Construct a binary search tree with some data
    BstNode<int>* root = new BstNode<int>(5);
    root->left = new BstNode<int>(3);
    root->right = new BstNode<int>(8);
    root->left->left = new BstNode<int>(1);
    root->left->right = new BstNode<int>(4);
    root->right->left = new BstNode<int>(7);
    root->right->right = new BstNode<int>(10);

    // Find the 3 largest elements in the tree
    int k = 3;
    std::vector<int> k_largest_elements = FindKLargestInBST(root, k);

    // Print the results
    std::cout << "The " << k << " largest elements in the tree are: ";
    for (int i = 0; i < k_largest_elements.size(); ++i) {
        std::cout << k_largest_elements[i] << " ";
    }
    std::cout << std::endl;

    // Free the memory allocated for the tree
    //DeleteTree(root);

    return 0;
}