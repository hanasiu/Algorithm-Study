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

Node* ReverseUsblist(Node* L, int start, int finish)
{
	auto dummy_head = L;
	auto sublist_head = dummy_head;
	int k = 1;
	while (k++ < start) { // start 까지 이동
		sublist_head = sublist_head->next;
	} 

	//dubug
	LinkedList list1;
	list1.inputHead(dummy_head);

	auto sublist_iter = sublist_head->next;
	while (start++ < finish) {
		auto temp = sublist_iter->next; // temp - start
		cout << "temp: " << (*temp).data << endl;
		sublist_iter->next = temp->next; // si - temp -n
		cout << "sublist_iter: " << (*sublist_iter).data << endl;
		cout << "sublist_iter->next: " << (*(sublist_iter->next)).data << endl;
		temp->next = sublist_head->next; // temp-n - 처음
		cout << "temp->next: " << (*(temp->next)).data << endl;
		cout << "sublist_head: " << (*sublist_head).data << endl;
		sublist_head->next = temp; // 
		cout << "sublist_head->next: " << (*(sublist_head->next)).data << endl;
		list1.printList();
		cout << endl;
	}
	
	return dummy_head->next;
}



int main()
{
	LinkedList list;
	
	list.insertNode(1);
	list.insertNode(2);
	list.insertNode(3);
	list.insertNode(4);
	list.insertNode(5);
	list.insertNode(6);
	list.insertNode(7);
	list.insertNode(8);
	list.insertNode(9);
	list.insertNode(10);

	list.printList();
	cout << endl;

	ReverseUsblist(list.returnHead(), 1, 8);

	list.printList();

	return 0;
}
