/**
 * Problem: Reverse Doubly Linked List
 * Reverse a doubly linked list by swapping next and prev pointers.
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
#include <iostream>
#include "DoublyListNode.h"

using namespace std;

DoublyListNode *reverseDoublyLL(DoublyListNode *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;
    DoublyListNode *cur = head;
    DoublyListNode *prevNode = nullptr;

    while (cur != nullptr)
    {
        DoublyListNode *nextNode = cur->next;
        cur->next = prevNode;
        cur->prev = nextNode;
        prevNode = cur;
        cur = nextNode;
    }

    return prevNode;
}