#include "./Binary.h"

int GetDepth(BinaryTreeNode<int>* node) {
    int depth = 0;
    while(node->parent) {
        ++depth, node = node->parent;
    }
    return depth;
}

BinaryTreeNode<int>* Lca(BinaryTreeNode<int>* node0,
BinaryTreeNode<int>* node1) {
    BinaryTreeNode<int>* iter0 = node0, *iter1 = node1;
    int depth0 = GetDepth(iter0), depth1 = GetDepth(iter1);
    if(depth1>depth0) {
        std::swap(iter0, iter1);
    }
    int depth_diff = abs(depth0 - depth1);
    while(depth_diff--) {
        iter0 = iter0 -> parent;
    }

    while(iter0 != iter1) {
        iter0 = iter0->parent, iter1 = iter1->parent;
    }
    return iter0;
}

int main() {
    BinaryTreeNode<int>* root = nullptr;
    insert(root, 5);
    insert(root, 3);
    insert(root, 8);
    insert(root, 2);
    insert(root, 4);
    insert(root, 7);
    insert(root, 9);

    std::cout << "Inorder traversal of the binary search tree: ";
    printInorder(root);
    std::cout << std::endl;

    // Test case
    BinaryTreeNode<int>* node2 = root->left->left;
    BinaryTreeNode<int>* node4 = root->left->right;
    BinaryTreeNode<int>* lca = Lca(node2, node4);
    std::cout << "LCA of nodes " << node2->data << " and " << node4->data << " is " << lca->data << std::endl;

    return 0;
}