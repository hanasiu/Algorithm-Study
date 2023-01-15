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

//https://www.geeksforgeeks.org/program-to-implement-singly-linked-list-in-c-using-class/
