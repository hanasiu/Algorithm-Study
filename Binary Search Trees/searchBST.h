#pragma once
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

template <typename T>
struct BstNode {
	T data;
    BstNode<T>* left;
    BstNode<T>* right;

    // Constructor
    BstNode(const T& data, BstNode<T>* left = nullptr, BstNode<T>* right = nullptr)
        : data(data), left(left), right(right) {}

    // Destructor
    ~BstNode() {
        delete left;
        delete right;
    }
};

BstNode<int>* searchBST(BstNode<int>* tree, int key) {
	if (tree == nullptr) {
		return nullptr;
	}
	return tree->data == key ? tree : key < tree->data ? searchBST(tree->left, key)
		: searchBST(tree->right, key);
}

template <typename T>
void DeleteTree(BstNode<T>* root) {
    if (root) {
        DeleteTree(root->left);
        DeleteTree(root->right);
        delete root;
    }
}

