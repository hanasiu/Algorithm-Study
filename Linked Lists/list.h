#pragma once
#include <iostream>
#include <vector>
#include <memory>

using namespace std;


template <typename T>
struct ListNode {
	T data;
	shared_ptr<ListNode<T>> next;
};

shared_ptr<ListNode<int>> searchList(shared_ptr<ListNode<int>> L, int key) {
	while (L && L->data != key) {
		L = L->next;
	}
	return L;
}

void insertAfter(const shared_ptr<ListNode<int>>& node, const shared_ptr<ListNode<int>>& new_node) {
	new_node->next = node->next;
	node->next = new_node;
}

void deleteAfter(const shared_ptr<ListNode<int>>& node) {
	node->next = node->next->next;
}

