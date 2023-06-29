#include <iostream>

using namespace std;

template <typename T>
struct BinaryTreeNode {
    T data;
    BinaryTreeNode* left;
    BinaryTreeNode* right;
    BinaryTreeNode* next;
    //BinaryTreeNode* parent;

    BinaryTreeNode(T val) : data(val), left(nullptr), right(nullptr), next(nullptr) {}
    BinaryTreeNode(T val, BinaryTreeNode* l, BinaryTreeNode* r) : data(val), left(l), right(r) {}

    ~BinaryTreeNode() {
    delete left;
    left = nullptr;
    delete right;
    right = nullptr;
    delete next;
    next = nullptr;
}
};

void PopulateLowerLevelNextField(BinaryTreeNode<int>* start_node) {
    while(start_node) {
        start_node -> left -> next = start_node -> right;
        if(start_node->next) {
            start_node -> right -> next = start_node -> next ->left;
        }
        start_node = start_node -> next;
    }
}

void ConstructRightSibling(BinaryTreeNode<int>* tree) {
    while(tree&&tree->left) {
        PopulateLowerLevelNextField(tree);
        tree = tree->left;
    }
}

int main() {
    // Create a binary tree with some nodes
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(1);
    root->left = new BinaryTreeNode<int>(2);
    root->right = new BinaryTreeNode<int>(3);
    root->left->left = new BinaryTreeNode<int>(4);
    root->left->right = new BinaryTreeNode<int>(5);
    root->right->left = new BinaryTreeNode<int>(6);
    root->right->right = new BinaryTreeNode<int>(7);

    // Construct the right siblings
    ConstructRightSibling(root);

    // Print the next field of each node
    BinaryTreeNode<int>* current = root;
    while (current) {
        BinaryTreeNode<int>* temp = current;
        while (temp) {
            cout << temp->data << "'s next: ";
            if (temp->next) {
                cout << temp->next->data;
            } else {
                cout << "nullptr";
            }
            cout << endl;
            temp = temp->next;
        }
        cout << endl;
        current = current->left;
    }

    return 0;
}
