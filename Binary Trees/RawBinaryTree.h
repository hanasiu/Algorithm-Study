#pragma once
using namespace std;

template <typename T>
struct BinaryTreeNode {
	T data;
	BinaryTreeNode* left;
	BinaryTreeNode* right;
	BinaryTreeNode* parent;

    ~BinaryTreeNode() {
    delete left;
    delete right;
  }
};