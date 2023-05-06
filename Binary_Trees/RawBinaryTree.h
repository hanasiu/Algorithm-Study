#pragma once
using namespace std;

template <typename T>
struct BinaryTreeNode {
    T data;
    BinaryTreeNode* left;
    BinaryTreeNode* right;
    BinaryTreeNode* parent;

    BinaryTreeNode(T val) : data(val), left(nullptr), right(nullptr), parent(nullptr) {}

    ~BinaryTreeNode() {
        delete left;
        delete right;
    }
};