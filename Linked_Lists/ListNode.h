#pragma once

struct ListNode {
	int data;
    ListNode* next;

    ListNode(int value = 0, ListNode* ptr = nullptr) : data(value), next(ptr) {}

    void Insert(int value) {
        ListNode* new_node = new ListNode(value, next);
        next = new_node;
    }
};