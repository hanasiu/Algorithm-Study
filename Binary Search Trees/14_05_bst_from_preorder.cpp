#include <iostream>
#include <vector>
#include <limits>

using namespace std;

struct BstNode {
    int data;
    BstNode* left;
    BstNode* right;

    // Constructor
    BstNode(int data, BstNode* left = nullptr, BstNode* right = nullptr)
        : data(data), left(left), right(right) {}

    // Destructor
    ~BstNode() {
        delete left;
        delete right;
    }
};

BstNode* RebuildBSTFromPreorderOnValueRange(const vector<int>& preorder_sequence, int lower_bound, int upper_bound, int* root_idx_ptr) {
    int& root_idx = *root_idx_ptr;
    if (root_idx == preorder_sequence.size()) {
        return nullptr;
    }

    int root = preorder_sequence[root_idx];
    if (root < lower_bound || root > upper_bound) {
        return nullptr;
    }

    BstNode* root_node = new BstNode(root);
    ++root_idx;
    cout << "root_idx: " << root_idx << endl;
    root_node->left = RebuildBSTFromPreorderOnValueRange(preorder_sequence, lower_bound, root, root_idx_ptr);
    root_node->right = RebuildBSTFromPreorderOnValueRange(preorder_sequence, root, upper_bound, root_idx_ptr);
    return root_node;
}

BstNode* RebuildBSTFromPreorder(const vector<int>& preorder_sequence) {
    int root_idx = 0;
    return RebuildBSTFromPreorderOnValueRange(preorder_sequence, numeric_limits<int>::min(), numeric_limits<int>::max(), &root_idx);
}

void PrintBstInorder(BstNode* node) {
    if (node) {
        PrintBstInorder(node->left);
        cout << node->data << " ";
        PrintBstInorder(node->right);
    }
}

int main() {
    vector<int> i = {43, 23, 37, 29, 31,41,47,53};
    BstNode* k = RebuildBSTFromPreorder(i);
    PrintBstInorder(k);
    delete k;
    return 0;
}