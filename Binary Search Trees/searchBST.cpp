#pragma once
#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;

template <typename T>
struct BstNode {
	T data;
	unique_ptr<BstNode<T>> left, right;
};

BstNode<int>* searchBST(const unique_ptr<BstNode<int>>& tree, int key) {
	if (tree == nullptr) {
		return nullptr;
	}
	return tree->data == key ? tree.get() : key < tree->data ? searchBST(tree->left, key)
		: searchBST(tree->right, key);
}

int main()
{
	
	return 0;
}
