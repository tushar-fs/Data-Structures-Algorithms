#include <iostream>
#include "ListNode.h"

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode *child;

    ListNode(int val)
    {
        this->val = val;
        this->next = nullptr;
        this->child = nullptr;
    }
};

ListNode *merge2SortedList(ListNode *l1, ListNode *l2)
{
    if (l1 == nullptr)
        return l2;
    else if (l2 == nullptr)
        return l1;

    ListNode *dummy = new ListNode(-1);
    ListNode *cur = dummy;
    while (l1 && l2)
    {
        if (l1->val <= l2->val)
        {
            cur->next = l1;
            l1 = l1->next;
        }
        else
        {
            cur->next = l2;
            l2 = l2->next;
        }
        cur = cur->next;
    }

    if (l1)
        cur->next = l1;
    else if (l2)
        cur->next = l2;
    ListNode *mergedHead = dummy->next;
    delete dummy;
    return mergedHead;
}

ListNode *flatten(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;

    ListNode *next = flatten(head->next);

    ListNode *child = flatten(head->child);
    
    return merge2SortedList(head, merge2SortedList(next, child));
}