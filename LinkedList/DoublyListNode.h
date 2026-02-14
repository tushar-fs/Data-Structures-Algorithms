#ifndef LISTNODE_H
#define LISTNODE_H

struct DoublyListNode
{
    int val;
    DoublyListNode *prev;
    DoublyListNode *next;
    DoublyListNode(int val)
    {
        this->val = val;
        this->prev = nullptr;
        this->next = nullptr;
    }
};

#endif