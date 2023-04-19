#include <iostream>
#include <vector>
#include "ListNode.h";


using namespace std;


void AppendNode(ListNode*& node, ListNode*& tail) {
	tail->next = node;
	tail = node;
	node = node->next;
}


ListNode* MergeTwoSortedLists(ListNode* L1, ListNode* L2) {
	ListNode* dummy_head = new ListNode(0, nullptr);
	auto tail = dummy_head;

	while (L1 && L2) {
		AppendNode(L1->data <= L2->data ? L1 : L2, tail);
	}

	tail->next = L1 ? L1 : L2;
	return dummy_head->next;
}
