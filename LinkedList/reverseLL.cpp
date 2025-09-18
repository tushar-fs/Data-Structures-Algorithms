#include <iostream>
#include "ListNode.h"

using namespace std;

void reverseLL(ListNode *head, ListNode *prev, ListNode *&newHead)
{
    if (head == nullptr)
    {
        newHead = prev;
        return;
    }

    ListNode *nextNode = head->next;
    head->next = prev;
    reverseLL(nextNode, head, newHead);
}

void printLL(ListNode *head)
{
    if (head == nullptr)
        return;

    cout << head->val << " ";
    printLL(head->next);
}

int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    ListNode *newHead;
    reverseLL(head, nullptr, newHead);
    printLL(newHead);
}