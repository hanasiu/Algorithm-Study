#include <iostream>
#include "ListNode.h"

ListNode* HasCycle(ListNode* const head) {
	ListNode* fast = head; ListNode* slow = head;

	while (fast && fast->next) {
		slow = slow->next, fast = fast->next->next;
		int cycle_len = 0;
		if (slow == fast) {
			do {
				++cycle_len;
				fast = fast->next;
			} while (slow != fast);


			auto cycle_len_advanced_iter = head;
			while (cycle_len--) {
				cycle_len_advanced_iter = cycle_len_advanced_iter->next;
			}

			auto iter = head;
			while (iter != cycle_len_advanced_iter) {
				iter = iter->next;
				cycle_len_advanced_iter = cycle_len_advanced_iter->next;
			}
			return iter;
		}
	}
	return nullptr;
}

int Length(ListNode* L)
{
    int length = 0;
    while (L)
    {
        ++length, L = L->next;
    }
    return length;
}

void AdvanceListByK(int k, ListNode* L)
{
    while (k--)
    {
        L = L->next;
    }
}

ListNode* OverlappingNoCycleLists(
    ListNode* l1, ListNode* l2)
{
    int l1_len = Length(l1), l2_len = Length(l2);

    AdvanceListByK(abs(l1_len - l2_len), l1_len > l2_len ? l1 : l2);

    while (l1 && l2 && l1 != l2)
    {
        l1 = l1->next, l2 = l2->next;
    }
    return l1;
}

ListNode* OverlappingLists(ListNode* l0, ListNode* l1) {
    auto root0 = HasCycle(l0), root1 = HasCycle(l1);

    if(!root0 && !root1) {
        return OverlappingNoCycleLists(l0, l1);
    } else if((root0 && !root1) || (!root0 && root1)) {
        return nullptr;
    }

    auto temp = root1;
    do {
        temp = temp->next;
    } while(temp != root0 && temp != root1);

    return temp == root0 ? root1 : nullptr;
}

int Distance(ListNode* a, ListNode* b) {
    int dis = 0;
    while (a != b) {
        a= a->next, ++dis;
    }
    return dis;
}

int main() {
    // Create linked lists
    ListNode* commonNode = new ListNode(8);
    commonNode->Insert(7);
    commonNode->Insert(6);

    ListNode* l0 = new ListNode(3);
    l0->Insert(1);
    l0->Insert(4);
    l0->next->next->next = commonNode;

    ListNode* l1 = new ListNode(5);
    l1->Insert(9);
    l1->next->next = commonNode;

    // Test overlapping lists function
    ListNode* overlapNode = OverlappingLists(l0, l1);

    if (overlapNode) {
        std::cout << "The lists overlap at node with data: " << overlapNode->data << std::endl;
    } else {
        std::cout << "The lists do not overlap." << std::endl;
    }

    // Clean up memory
    delete l0;
    delete l1;

    return 0;
}
