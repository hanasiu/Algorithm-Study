#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

#include <iostream>

template <typename T>
struct BinaryTreeNode
{
    T data;
    BinaryTreeNode<T> *left, *right;
    BinaryTreeNode<T> *parent;
};

// template <typename T>
// void insert(BinaryTreeNode<T> *&root, T data, BinaryTreeNode<T> *parent = nullptr)
// {
//     if (root == nullptr)
//     {
//         root = new BinaryTreeNode<T>{data, nullptr, nullptr, parent};
//     }
//     else
//     {
//         if (data < root->data)
//         {
//             insert(root->left, data, root);
//         }
//         else
//         {
//             insert(root->right, data, root);
//         }
//     }
// }

template <typename T>
void printInorder(BinaryTreeNode<T> *root)
{
    if (root == nullptr)
    {
        return;
    }
    printInorder(root->left);
    std::cout << root->data << " ";
    printInorder(root->right);
}

BinaryTreeNode<int> *BinaryTreeFromPreorderInorderHelper(
    const vector<int> &preorder, size_t preorder_start, size_t preorder_end,
    size_t inorder_start, size_t inorder_end,
    const unordered_map<int, size_t> &node_to_inorder_idx)
{
    if (preorder_end <= preorder_start || inorder_end <= inorder_start)
    {
        return nullptr;
    }
    size_t root_inorder_idx = node_to_inorder_idx.at(preorder[preorder_start]);
    size_t left_subtree_size = root_inorder_idx - inorder_start;

    return new BinaryTreeNode<int>{
        preorder[preorder_start],
        BinaryTreeFromPreorderInorderHelper(
            preorder, preorder_start + 1,
            preorder_start + 1 + left_subtree_size, inorder_start,
            root_inorder_idx, node_to_inorder_idx),
        BinaryTreeFromPreorderInorderHelper(
            preorder, preorder_start + 1 + left_subtree_size, preorder_end,
            root_inorder_idx + 1, inorder_end, node_to_inorder_idx),
        nullptr};
}

BinaryTreeNode<int> *BinaryTreeFromPreorderInorder(
    const vector<int> &preorder, const vector<int> &inorder)
{
    unordered_map<int, size_t> node_to_inorder_idx;
    for (size_t i = 0; i < inorder.size(); ++i)
    {
        node_to_inorder_idx.emplace(inorder[i], i);
    }
    return BinaryTreeFromPreorderInorderHelper(
        preorder, 0, preorder.size(), 0, inorder.size(), node_to_inorder_idx);
}

int main()
{
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};

    BinaryTreeNode<int>* root = BinaryTreeFromPreorderInorder(preorder, inorder);
    printInorder(root);

    return 0;
}