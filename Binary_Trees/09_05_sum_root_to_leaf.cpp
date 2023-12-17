#include <iostream>


using namespace std;


struct BinaryTreeNode {
    int data;
    BinaryTreeNode* left;
    BinaryTreeNode* right;
    BinaryTreeNode* next;
    //BinaryTreeNode* parent;

    BinaryTreeNode(int val) : data(val), left(nullptr), right(nullptr), next(nullptr) {}
    BinaryTreeNode(int val, BinaryTreeNode* l, BinaryTreeNode* r) : data(val), left(l), right(r) {}

    ~BinaryTreeNode() {
    delete left;
    left = nullptr;
    delete right;
    right = nullptr;
    delete next;
    next = nullptr;
}
};

int SumRootToLeafHelper(const BinaryTreeNode* tree, int partial_path_sum) {
    if(tree == nullptr) {
        return 0;
    }

    partial_path_sum = partial_path_sum * 2 + tree->data;
    if(tree->left == nullptr && tree->right == nullptr) {
        return partial_path_sum;
    }

    return SumRootToLeafHelper(tree->left, partial_path_sum) +
    SumRootToLeafHelper(tree->right, partial_path_sum);
}

int SumRootToLeaf(const BinaryTreeNode* tree) {
    return SumRootToLeafHelper(tree, 0);
}


int main() {
    // Creating a binary tree
    BinaryTreeNode* root = new BinaryTreeNode(1);
    root->left = new BinaryTreeNode(0);
    root->right = new BinaryTreeNode(1);
    root->left->left = new BinaryTreeNode(0);
    root->left->right = new BinaryTreeNode(1);
    root->right->left = new BinaryTreeNode(0);
    root->right->right = new BinaryTreeNode(1);

    // Testing the SumRootToLeaf function
    int result = SumRootToLeaf(root);

    // Displaying the result
    cout << "Sum of binary numbers formed by root-to-leaf paths: " << result << endl;

    // Cleaning up the allocated memory
    delete root;

    return 0;
}
