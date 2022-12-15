#include <iostream>
#include <vector>

using namespace std;

//header

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
//header

//sorted_lists_merge.cpp

void AppendNode(shared_ptr<listNode<int>>* node,
	shared_ptr<listNode<int>>* tail) {
	(*tail)->next = *node;
	*tail = *node;
	*node = (*node)->next;
}

shared_ptr<listNode<int>> MergeTwoSortedLists(shared_ptr<listNode<int>> L1,
	shared_ptr<listNode<int>> L2) {
	shared_ptr<listNode<int>> dummy_head(new listNode<int>);
	auto tail = dummy_head;

	while (L1 && L2) {
		AppendNode(L1->data <= L2->data ? &L1 : &L2, &tail);
	}

	tail->next = L1 ? L1 : L2;
	return dummy_head->next;
}


int main()
{
	
	return 0;
}
