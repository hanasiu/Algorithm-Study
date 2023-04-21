#include <iostream>
#include <unordered_set>

using namespace std;

template <typename T>
struct BinaryTreeNode {
	T data;
	BinaryTreeNode* left;
	BinaryTreeNode* right;
	BinaryTreeNode* parent;

    ~BinaryTreeNode() {
    delete left;
    delete right;
  }
};

BinaryTreeNode<int>* Lca(BinaryTreeNode<int>* node0, 
BinaryTreeNode<int>* node1) {
    BinaryTreeNode<int>* iter0 = node0, *iter1 = node1;
    unordered_set<BinaryTreeNode<int>*> nodes_on_path_to_root;
    while(iter0 || iter1) {
        if(iter0) {
        if(nodes_on_path_to_root.emplace(iter0).second == false) {
            return iter0;
        }
        iter0 = iter0->parent;
    }
    if(iter1) {
        if(nodes_on_path_to_root.emplace(iter1).second == false) {
            return iter1;
        }
        iter1 = iter1 -> parent;
    }
    }
    throw invalid_argument("node0 and node1 are not in the same tree");
}

int main() {
  // create the nodes
  BinaryTreeNode<int>* root = new BinaryTreeNode<int>{1, nullptr, nullptr, nullptr};
  BinaryTreeNode<int>* node2 = new BinaryTreeNode<int>{2, nullptr, nullptr, root};
  BinaryTreeNode<int>* node3 = new BinaryTreeNode<int>{3, nullptr, nullptr, root};
  BinaryTreeNode<int>* node4 = new BinaryTreeNode<int>{4, nullptr, nullptr, node2};
  BinaryTreeNode<int>* node5 = new BinaryTreeNode<int>{5, nullptr, nullptr, node2};
  BinaryTreeNode<int>* node6 = new BinaryTreeNode<int>{6, nullptr, nullptr, node3};
  BinaryTreeNode<int>* node7 = new BinaryTreeNode<int>{7, nullptr, nullptr, node3};

  // link the nodes together to form a binary tree
  root->left = node2;
  root->right = node3;
  node2->left = node4;
  node2->right = node5;
  node3->left = node6;
  node3->right = node7;
  /*
      1
    2   3
   4 5 6 7
  */
  BinaryTreeNode<int>* i = Lca(node4, node5);
  cout << i->data << endl; 
  BinaryTreeNode<int>* k = Lca(node6, node7);
  cout << k->data << endl; 
  BinaryTreeNode<int>* j = Lca(node2, node7);
  cout << j->data << endl; 

  delete root;
  return 0;
}