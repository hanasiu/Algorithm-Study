#pragma once
using namespace std;

template <typename T>
struct BinaryTreeNode {
    T data;
    BinaryTreeNode* left;
    BinaryTreeNode* right;
    //BinaryTreeNode* parent;

    BinaryTreeNode(T val) : data(val), left(nullptr), right(nullptr) {}
    BinaryTreeNode(T val, BinaryTreeNode* l, BinaryTreeNode* r) : data(val), left(l), right(r) {}

    ~BinaryTreeNode() {
    delete left;
    left = nullptr;
    delete right;
    right = nullptr;
}
};