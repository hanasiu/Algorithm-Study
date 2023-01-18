#include <iostream>
using namespace std;

class Node {
public:
	int data;
	Node* next;

	Node()
	{
		data = 0;
		next = NULL;
	}

	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
};

class LinkedList {
	Node* head;
public:
	
	LinkedList() { head = NULL; }

	Node* returnHead() { return head; }
	Node* inputHead(Node* i) { head = i; return head; }
	Node* returnLastNode() { 
		Node* index = head;
		while (index->next) {
			index = index->next;
		}
		return index;
	}
	void insertNode(int);
	void printList();
	void deleteNode(int);
};

void LinkedList::deleteNode(int nodeOffset)
{
	Node* temp1 = head, * temp2 = NULL;
	int ListLen = 0;

	if (head == NULL) {
		cout << "List empty." << endl;
		return;
	}

	while (temp1 != NULL) {
		temp1 = temp1->next;
		ListLen++;
	}

	if (ListLen < nodeOffset) {
		cout << "Index out of range"
			<< endl;
		return;
	}

	temp1 = head;

	if (nodeOffset == 1) {
		head = head->next;
		delete temp1;
		return;
	}

	while (nodeOffset-- > 1) {
		temp2 = temp1;
		temp1 = temp1->next;
	}

	temp2->next = temp1->next;
	
	delete temp1;
}

void LinkedList::insertNode(int data)
{
	Node* newNode = new Node(data);

	if (head == NULL) {
		head = newNode;
		return;
	}

	Node* temp = head;
	while (temp->next != NULL) {
		temp = temp->next;
	}

	temp->next = newNode;
}

void LinkedList::printList()
{
	Node* temp = head;

	if (head == NULL) {
		cout << "List empty" << endl;
		return;
	}

	while (temp != NULL) {
		cout << temp->data << " ";
		temp = temp->next;
	}
}

Node* HasCycle(Node* const head) {
	Node* fast = head; Node* slow = head;

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

int main()
{
	LinkedList list;
	int i = 1;
	Node* five = list.returnHead();
	while (i <= 10) {
		list.insertNode(i);
		if (i == 5) {
			five = list.returnLastNode();
		}
		++i;
	}
	Node* last = list.returnLastNode();
	last->next = five;
	Node* result = HasCycle(list.returnHead());
	cout << result->data;
	
	return 0;
}
