#include <iostream>
#include <vector>


using namespace std;


struct ListNode {
	int data;
    ListNode* next;

    ListNode(int value = 0, ListNode* ptr = nullptr) : data(value), next(ptr) {}

    void Insert(int value) {
        ListNode* new_node = new ListNode(value, next);
        next = new_node;
    }
};

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

ListNode* StableSortList(ListNode* L) {
    if(L == nullptr || L->next == nullptr) {
        return L;
    }

    ListNode* pre_slow = nullptr, *slow = L, *fast = L;
    while(fast&&fast->next) {
        pre_slow = slow;
        fast = fast->next->next, slow = slow->next;
    }

    if(pre_slow) {
        pre_slow->next = nullptr;
    }
    return MergeTwoSortedLists(StableSortList(L), StableSortList(slow));
}

int main() {
    // Create an empty list
    ListNode* test_list = new ListNode(); 

    // Insert some unsorted elements into the list
    test_list->Insert(4);
    test_list->Insert(1);
    test_list->Insert(3);
    test_list->Insert(2);
    test_list->Insert(5);

    // Sort the list and print the sorted values
    ListNode* sorted_list = StableSortList(test_list);
    while (sorted_list) {
        cout << sorted_list->data << " ";
        sorted_list = sorted_list->next;
    }

    // Output should be: 1 2 3 4 5
    return 0;
}