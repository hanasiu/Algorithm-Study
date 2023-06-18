
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct BinaryTreeNode
{
    int data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;

    BinaryTreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
    BinaryTreeNode(int val, BinaryTreeNode *l, BinaryTreeNode *r) : data(val), left(l), right(r) {}

    ~BinaryTreeNode()
    {
        delete left;
        delete right;
    }
};
BinaryTreeNode *ReconstructPreorderHelper(const std::vector<int *> &preorder, int *subtree_idx_pointer)
{

    int &subtree_idx = *subtree_idx_pointer;
    // cout << subtree_idx << endl;
    if (subtree_idx >= preorder.size())
    {
        return nullptr;
    }
    int *subtree_key = preorder[subtree_idx];
    ++subtree_idx;

    if (subtree_key == nullptr)
    {
        return nullptr;
    }

    // std::cout << *subtree_key << std::endl;

    BinaryTreeNode *left_subtree = ReconstructPreorderHelper(preorder, subtree_idx_pointer);
    BinaryTreeNode *right_subtree = ReconstructPreorderHelper(preorder, subtree_idx_pointer);

    return new BinaryTreeNode(*subtree_key, left_subtree, right_subtree);
}

BinaryTreeNode *ReconstructPreorder(
    const std::vector<int *> &preorder)
{
    int subtree_idx_pointer = 0;
    return ReconstructPreorderHelper(preorder, &subtree_idx_pointer);
}

void PrintTree(BinaryTreeNode *root)
{
    if (root == nullptr)
    {
        return;
    }

    std::queue<BinaryTreeNode *> nodeQueue;
    nodeQueue.push(root);

    while (!nodeQueue.empty())
    {
        int levelSize = nodeQueue.size();

        for (int i = 0; i < levelSize; ++i)
        {
            BinaryTreeNode *current = nodeQueue.front();
            nodeQueue.pop();

            if (current != nullptr)
            {
                std::cout << char(current->data) << " ";

                nodeQueue.push(current->left);
                nodeQueue.push(current->right);
            }
            else
            {
                std::cout << "null ";
            }
        }

        std::cout << std::endl;
    }
}

int main()
{
    std::vector<int *> preorder;
    preorder.push_back(new int('H'));
    preorder.push_back(new int('B')); // Node with value 1
    preorder.push_back(new int('F')); // Node with value 2
    preorder.push_back(nullptr);
    preorder.push_back(nullptr); // Empty node
    preorder.push_back(new int('E'));
    preorder.push_back(new int('A')); // Node with value 3
    preorder.push_back(nullptr);      // Empty node
    preorder.push_back(nullptr);
    preorder.push_back(nullptr); // Empty node
    preorder.push_back(new int('C'));
    preorder.push_back(nullptr);
    preorder.push_back(new int('D'));
    preorder.push_back(nullptr);
    preorder.push_back(new int('G'));
    preorder.push_back(new int('I'));
    preorder.push_back(nullptr); // Empty node
    preorder.push_back(nullptr);
    preorder.push_back(nullptr);

    // Reconstruct the binary tree
    BinaryTreeNode *root = ReconstructPreorder(preorder);

    PrintTree(root);
    std::cout << std::endl;

    // // Delete the dynamically allocated integers in the preorder vector
    // for (int* ptr : preorder) {
    //     delete ptr;
    // }

    // // Clean up memory
    // delete root;

    return 0;
}