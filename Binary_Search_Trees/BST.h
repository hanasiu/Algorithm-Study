#include <iostream>

class BstNode {
    public:
    int data;
    BstNode* left;
    BstNode* right;

    // Constructor
    BstNode(const int& data, BstNode* left = nullptr, BstNode* right = nullptr)
        : data(data), left(left), right(right) {}

    // Destructor
    ~BstNode() {
        delete left;
        delete right;
    }
};

BstNode* searchBST(BstNode* tree, int key) {
    if (tree == nullptr) {
        return nullptr;
    }
    return tree->data == key ? tree : key < tree->data ? searchBST(tree->left, key)
        : searchBST(tree->right, key);
}

void PrintBstInorder(BstNode* node) {
    if (node) {
        PrintBstInorder(node->left);
        std::cout << node->data << " ";
        PrintBstInorder(node->right);
    }
}