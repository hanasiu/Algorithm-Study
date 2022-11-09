#pragma once
#include <iostream>
#include <memory>

using namespace std;

template <typename T>
struct BinaryTreeNode {
	T data;
	unique_ptr<BinaryTreeNode<T>> left, right;
};

void treeTraversal(const unique_ptr<BinaryTreeNode<int>>& root) {
	if (root) {
		cout << "Preorder: " << root->data << endl;
		treeTraversal(root->left);
		cout << "Inorder: " << root->data << endl;
		treeTraversal(root->right);
		cout << "Postorder: " << root->data << endl;
	}
}
