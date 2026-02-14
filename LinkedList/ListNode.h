#ifndef LISTNODE_H
#define LISTNODE_H

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int val)
    {
        this->val = val;
        this->next = nullptr;
    }
};

#endif