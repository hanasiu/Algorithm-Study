#include <iostream>
#include "ListNode.h"

using namespace std;

ListNode *ReverseList(ListNode *head)
{
    ListNode *prev = nullptr;
    ListNode *current = head;
    ListNode *next = nullptr;

    while (current != nullptr)
    {
        //cout << char(current->data)<< endl;
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
}

bool IsLinkedListAPalindrome(ListNode *L)
{
    ListNode *slow = L, *fast = L;
    while (fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
        // cout << "s " << char(slow->data) << endl;
        // cout << "f " << char(fast->data) << endl;
    }

    auto first_half_iter = L, second_half_iter = ReverseList(slow);
    while (second_half_iter && first_half_iter)
    {
        if (second_half_iter->data != first_half_iter->data)
        {
            return false;
        }
        second_half_iter = second_half_iter->next;
        first_half_iter = first_half_iter->next;
    }
    return true;
}

int main()
{
    // Test function using "madam"
    ListNode *head = new ListNode('m');
    head->Insert('m');
    head->Insert('a');
    head->Insert('d');
    head->Insert('a');

    std::cout << "Linked List: ";
    ListNode *iter = head;
    while (iter != nullptr)
    {
        std::cout << static_cast<char>(iter->data) << " ";
        iter = iter->next;
    }
    std::cout << std::endl;

    if (IsLinkedListAPalindrome(head))
    {
        std::cout << "The linked list is a palindrome." << std::endl;
    }
    else
    {
        std::cout << "The linked list is not a palindrome." << std::endl;
    }

    // Clean up memory
    iter = head;
    while (iter != nullptr)
    {
        ListNode *temp = iter;
        iter = iter->next;
        delete temp;
    }

    return 0;
}
