
#include "incl.hpp"

/*
without inline
Runtime: 8 ms, faster than 63.79% of C++ online submissions for Reverse Linked List.
Memory Usage: 8.3 MB, less than 41.62% of C++ online submissions for Reverse Linked List.
Time S              ubmitted    Status  RuntimeMemory   Language
10/31/2021 18:06	Accepted	8 ms	8.3 MB	cpp
*/

ListNode *reverseList(ListNode *head)
{
    if (!head)
        return head;
    ListNode *pre = nullptr, *curr = head->next;
    while (true)
    {
        head->next = pre; //head 指向左邊的空
        pre = head;       //讓pre 往下移動所以變成head
        if (curr == nullptr)
            break;
        head = curr; //head往下移動

        curr = curr->next; //curr 往下移動
    }
    return head;
}
ListNode *reverseList(ListNode *head)
{
    /*
        Runtime: 4 ms, faster than 95.54% of C++ online submissions for Reverse Linked List.
        Memory Usage: 8.2 MB, less than 78.87% of C++ online submissions for Reverse Linked List.
    */
    ListNode *prev = NULL;
    ListNode *hd = head;
    ListNode *cur = NULL;

    while (hd)
    {
        cur = hd->next;
        hd->next = prev;
        prev = hd;
        hd = cur;
    }
    head = prev;
    return head;
}