#include "ListNode.h"
#include <iostream>
#include <array>

using namespace std;

ListNode* EvenOddMerge(ListNode* L) {
    if(L==nullptr) {
        return L;
    }

    auto even_dummy_head = new ListNode(); 
    auto odd_dummy_head = new ListNode();

    array<ListNode*, 2> tails = {even_dummy_head, odd_dummy_head};

    int turn = 0;
    for(auto iter = L; iter; iter = iter->next) {
        tails[turn]->next = iter;
        tails[turn] = tails[turn]->next;
        turn ^= 1;
    }
    tails[1]->next = nullptr;
    tails[0]->next = odd_dummy_head->next;
    return even_dummy_head->next;
}

int main() {
    // Create a sample linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(0);
    ListNode* node2 = new ListNode(1);
    ListNode* node3 = new ListNode(2);
    ListNode* node4 = new ListNode(3);
    ListNode* node5 = new ListNode(4);

    head->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;

    // Call EvenOddMerge function on the linked list
    ListNode* mergedList = EvenOddMerge(head);

    // Print the merged list
    for (ListNode* curr = mergedList; curr != nullptr; curr = curr->next) {
        cout << curr->data << " ";
    }
    cout << endl;

    // Clean up the memory (delete the allocated nodes)

    ListNode* curr = mergedList;
    while (curr != nullptr) {
        ListNode* nextNode = curr->next;
        delete curr;
        curr = nextNode;
    }

    return 0;
}