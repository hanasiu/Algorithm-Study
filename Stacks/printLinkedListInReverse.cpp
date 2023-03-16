#include <iostream>
#include <vector>
#include <stack>
#include <memory>

using namespace std;

template <typename T>
struct listNode {
	T data;
	shared_ptr<listNode<T>> next;
};

shared_ptr<listNode<int>> searchList(shared_ptr<listNode<int>> L, int key) {
	while (L && L->data != key) {
		L = L->next;
	}
	return L;
}

void insertAfter(const shared_ptr<listNode<int>>& node, const shared_ptr<listNode<int>>& new_node) {
	new_node->next = node->next;
	node->next = new_node;
}

void deleteAfter(const shared_ptr<listNode<int>>& node) {
	node->next = node->next->next;
}

void printLinkedListInReverse(shared_ptr<listNode<int>> head) {
	stack<int> nodes;
	while (head) {
		nodes.push(head->data);
		head = head->next;
	}
	while (!nodes.empty()) {
		cout << nodes.top() << endl;
		nodes.pop();
	}
}

int main()
{
	

	return 0;
}
