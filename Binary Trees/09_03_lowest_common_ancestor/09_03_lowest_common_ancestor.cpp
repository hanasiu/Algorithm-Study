#include "./Binary.h"

struct Status {
    int num_target_nodes;
    BinaryTreeNode<int>* ancestor;
    Status(int n, BinaryTreeNode<int>* a) : num_target_nodes(n), ancestor(a) {}
};

Status LcaHelper(const BinaryTreeNode<int>* tree,
const BinaryTreeNode<int>* node0,
const BinaryTreeNode<int>* node1) {
    if(tree == nullptr) {
        return Status(0, nullptr);
    }

    auto left_result = LcaHelper(tree->left, node0, node1);
    if(left_result.num_target_nodes == 2) {
        return left_result;
    }
    auto right_result = LcaHelper(tree->right, node0, node1);
    if(right_result.num_target_nodes == 2) {
        return right_result;
    }
    int num_target_nodes = left_result.num_target_nodes +
    right_result.num_target_nodes + (tree==node0) +
    (tree == node1);
    return Status(num_target_nodes, (num_target_nodes == 2 ? const_cast<BinaryTreeNode<int>*>(tree) : nullptr));
}

int main() {
    BinaryTreeNode<int>* root = nullptr;
    insert(root, 5);
    insert(root, 3);
    insert(root, 2);
    insert(root, 4);
    insert(root, 7);
    insert(root, 6);
    insert(root, 8);

    std::cout << "Inorder traversal of the binary search tree: ";
    printInorder(root);
    std::cout << std::endl;

    BinaryTreeNode<int>* node0 = root->left->left;   // node with value 2
    BinaryTreeNode<int>* node1 = root->right->right; // node with value 8
    Status result = LcaHelper(root, node0, node1);

    if (result.num_target_nodes == 2 && result.ancestor != nullptr) {
        std::cout << "Lowest common ancestor of " << node0->data << " and " << node1->data << " is " << result.ancestor->data << std::endl;
    }
    else {
        std::cout << "Lowest common ancestor of " << node0->data << " and " << node1->data << " not found!" << std::endl;
    }

    return 0;
}
