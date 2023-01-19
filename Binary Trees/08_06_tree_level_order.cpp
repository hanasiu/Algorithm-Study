#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class BinaryTree {
public:
    Node* root;

    BinaryTree() {
        root = nullptr;
    }

    void addNode(int data) {
        Node* newNode = new Node(data);

        if (root == nullptr) {
            root = newNode;
        }
        else {
            Node* focusNode = root;
            Node* parent;

            while (true) {
                parent = focusNode;

                if (data < focusNode->data) {
                    focusNode = focusNode->left;
                    if (focusNode == nullptr) {
                        parent->left = newNode;
                        return;
                    }
                }
                else {
                    focusNode = focusNode->right;
                    if (focusNode == nullptr) {
                        parent->right = newNode;
                        return;
                    }
                }
            }
        }
    }

    void preOrderTraversal(Node* focusNode) {
        if (focusNode != nullptr) {
            std::cout << focusNode->data << " ";
            preOrderTraversal(focusNode->left);
            preOrderTraversal(focusNode->right);
        }
    }
};

vector<vector<int>> BinaryTreeDepthOrder(BinaryTree* tree)
{
    vector<vector<int>> result;
    if (!tree) {
        return result;
    }

    queue<Node*> curr_depth_nodes({ tree->root });
    while (!curr_depth_nodes.empty()) {
        queue<Node*> next_depth_nodes;
        vector<int> this_level;
        while (!curr_depth_nodes.empty()) {
            auto curr = curr_depth_nodes.front();
            curr_depth_nodes.pop();
            this_level.emplace_back(curr->data);

            if (curr->left) {
                next_depth_nodes.emplace(curr->left);
            }
            if (curr->right) {
                next_depth_nodes.emplace(curr->right);
            }
        }
        result.emplace_back(this_level);
        curr_depth_nodes = next_depth_nodes;
    }
    return result;
}

int main() {
    BinaryTree tree;

    tree.addNode(6);
    tree.addNode(1);
    tree.addNode(7);
    tree.addNode(2);
    tree.addNode(8);
    tree.addNode(3);
    tree.addNode(9);
    tree.addNode(4);
    tree.addNode(10);


    tree.preOrderTraversal(tree.root);
    cout << endl;



    vector<vector<int>> i = BinaryTreeDepthOrder(&tree);
    for (auto k : i) {
        for (auto q : k) {
            cout << q << " ";
        }
        cout << endl;
    }

    return 0;
}


