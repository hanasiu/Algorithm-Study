#include "searchBST.h"
#include <iostream>

BstNode<int>* FindLca(BstNode<int> *tree,
                      BstNode<int> *s, BstNode<int> *b)
{
    auto p = tree;
    while (p->data < s->data || p->data > b->data)
    {
        while (p->data < s->data)
        {
            p = p->right;
        }
        while (p->data > b->data)
        {
            p = p->left;
        }
    }
    return p;
}

int main() {
    // Create a sample binary search tree
    BstNode<int>* root = new BstNode<int>(10);
    root->left = new BstNode<int>(5);
    root->right = new BstNode<int>(15);
    root->left->left = new BstNode<int>(3);
    root->left->right = new BstNode<int>(7);
    root->right->left = new BstNode<int>(12);
    root->right->right = new BstNode<int>(17);

    // Find the LCA of nodes 3 and 12
    BstNode<int>* lca = FindLca(root, root->left->left, root->right->left);
    std::cout << "LCA of 3 and 12 is: " << lca->data << std::endl;

    // Find the LCA of nodes 7 and 17
    lca = FindLca(root, root->left->right, root->right->right);
    std::cout << "LCA of 7 and 17 is: " << lca->data << std::endl;

    // Find the LCA of nodes 5 and 15
    lca = FindLca(root, root->left, root->right);
    std::cout << "LCA of 5 and 15 is: " << lca->data << std::endl;

        // Find the LCA of nodes 5 and 15
    lca = FindLca(root, root->right->left, root->right->right);
    std::cout << "LCA of 12 and 17 is: " << lca->data << std::endl;

    // Clean up the tree
    delete root;

    return 0;
}