#include <iostream>
using namespace std;

template <typename T>
class ListNode
{
public:
    T val;
    ListNode<T> *next;

    ListNode(T value)
    {
        val = value;
        next = nullptr;
    }
};

ListNode<int> *RemoveKthLast(ListNode<int> *L, int k)
{
    ListNode<int> *dummy_head = new ListNode<int>(0);
    dummy_head->next = L;
    auto first = dummy_head->next;
    while (k--)
    {
        first = first->next;
    }

    auto second = dummy_head;
    while (first)
    {
        second = second->next, first = first->next;
    }
    auto temp = second->next;
    second->next = second->next->next;
    delete temp;
    return dummy_head->next;
}

int main()
{
    // Create a linked list with values 1 -> 2 -> 3 -> 4 -> 5
    ListNode<int> *head = new ListNode<int>(1);
    head->next = new ListNode<int>(2);
    head->next->next = new ListNode<int>(3);
    head->next->next->next = new ListNode<int>(4);
    head->next->next->next->next = new ListNode<int>(5);

    // Print the original linked list
    cout << "Original linked list: ";
    auto curr = head;
    while (curr)
    {
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << endl;

    // Remove the 2nd last element (k = 2)
    head = RemoveKthLast(head, 2);

    // Print the modified linked list
    cout << "Modified linked list: ";
    curr = head;
    while (curr)
    {
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << endl;

    // Clean up the memory used by the linked list
    curr = head;
    while (curr)
    {
        auto temp = curr;
        curr = curr->next;
        delete temp;
    }

    return 0;
}