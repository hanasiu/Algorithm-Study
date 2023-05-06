#include <iostream>
#include <memory>

using namespace std;

//header
template <typename T>
struct BinaryTreeNode {
	T data;
	unique_ptr<BinaryTreeNode<T>> left, right;
};

void treeTraversal(const unique_ptr<BinaryTreeNode<int>>& root) {
	if (root) {
		cout << "Preorder: " << root->data << endl;
		treeTraversal(root->left);
		cout << "Inorder: " << root->data << endl;
		treeTraversal(root->right);
		cout << "Postorder: " << root->data << endl;
	}
}

//is_tree_balanced.cpp

struct BalancedStatusWithHeight {
	bool balanced;
	int height;
};

BalancedStatusWithHeight CheckBalanced(
	const unique_ptr<BinaryTreeNode<int>>& tree) {
	if (tree == nullptr) {
		return { true, -1 };
	}

	auto left_result = CheckBalanced(tree->left);
	if (!left_result.balanced) {
		return { false, 0 };
	}
	auto right_result = CheckBalanced(tree->right);
	if (!right_result.balanced) {
		return { false, 0 };
	}

	bool is_balanced = abs(left_result.height - right_result.height) <= 1;
	int height = max(left_result.height, right_result.height) + 1;
	return { is_balanced, height };
}

int main()
{
	
	return 0;
}
