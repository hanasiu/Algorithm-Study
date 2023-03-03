#include <iostream>
#include <vector>
#include <queue>
#include <memory>
#include <limits>

using namespace std;


//첫번째 해결책
template <typename T>
struct BinaryTreeNode {
	T data;
	unique_ptr<BinaryTreeNode<T>> left, right;
};

bool AreKeysInRange(const unique_ptr<BinaryTreeNode<int>>& tree,
	int low_range, int high_range) {
	if (tree == nullptr) {
		return true;
	}
	else if (tree->data < low_range || tree->data > high_range) {
		return false;
	}

	return AreKeysInRange(tree->left, low_range, tree->data) &&
		AreKeysInRange(tree->right, tree->data, high_range);
}

bool IsBinaryTreeBST(const unique_ptr<BinaryTreeNode<int>>& tree) {
	return AreKeysInRange(tree, numeric_limits<int>::min(),
		numeric_limits<int>::max());
}

//두번째 해결책
struct QueueEntry {
	const unique_ptr<BinaryTreeNode<int>>& tree_node;
	int lower_bound, upper_bound;
};

bool IsBinaryTreeBSTByQueue(const unique_ptr<BinaryTreeNode<int>>& tree) {
	queue<QueueEntry> bfs_queue;
	bfs_queue.emplace(QueueEntry{ tree, numeric_limits<int>::min(),
		numeric_limits<int>::max() });

	while (!bfs_queue.empty()) {
		if (bfs_queue.front().tree_node.get()) {
			if (bfs_queue.front().tree_node->data < bfs_queue.front().lower_bound ||
				bfs_queue.front().tree_node->data > bfs_queue.front().upper_bound) {
				return false;
			}

			bfs_queue.emplace(QueueEntry{ bfs_queue.front().tree_node->left,
				bfs_queue.front().lower_bound,
				bfs_queue.front().tree_node->data });
			bfs_queue.emplace(QueueEntry{ bfs_queue.front().tree_node->right,
				bfs_queue.front().tree_node->data,
				bfs_queue.front().upper_bound });
		}
		bfs_queue.pop();
	}
	return true;
}


int main()
{
	
	return 0;
}
