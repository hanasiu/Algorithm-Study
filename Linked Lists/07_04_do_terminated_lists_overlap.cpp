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

int Length(ListNode<int> *L)
{
    int length = 0;
    while (L)
    {
        ++length, L = L->next;
    }
    return length;
}

void AdvanceListByK(int k, ListNode<int> *L)
{
    while (k--)
    {
        L = L->next;
    }
}

ListNode<int> *OverlappingNoCycleLists(
    ListNode<int> *l1, ListNode<int> *l2)
{
    int l1_len = Length(l1), l2_len = Length(l2);

    AdvanceListByK(abs(l1_len - l2_len), l1_len > l2_len ? l1 : l2);

    while (l1 && l2 && l1 != l2)
    {
        l1 = l1->next, l2 = l2->next;
    }
    return l1;
}

int main() {
    // Create the first linked list
    ListNode<int>* l1 = new ListNode<int>(1);
    l1->next = new ListNode<int>(2);
    l1->next->next = new ListNode<int>(3);
    l1->next->next->next = new ListNode<int>(4);
    l1->next->next->next->next = new ListNode<int>(6);

    // Create the second linked list
    ListNode<int>* l2 = new ListNode<int>(5);
    l2->next = new ListNode<int>(6);
    l2->next->next = new ListNode<int>(7);
    l2->next->next->next = l1->next->next->next; // Overlap starts at node 4

    // Call the OverlappingNoCycleLists function
    ListNode<int>* overlap_node = OverlappingNoCycleLists(l1, l2);

    // Print the value of the overlapping node
    cout << overlap_node->val << endl;

    return 0;
}