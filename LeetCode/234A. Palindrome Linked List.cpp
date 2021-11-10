
#include "incl.hpp"

/*
Runtime: 264 ms, faster than 40.78% of C++ online submissions for Palindrome Linked List.
Memory Usage: 148.6 MB, less than 5.10% of C++ online submissions for Palindrome Linked List.
Time S              ubmitted    Status  RuntimeMemory   Language
11/06/2021 18:48	Accepted	264 ms	148.6 MB	cpp
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
ListNode *reverlist(ListNode *head)
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
    return prev;
}
bool isPalindrome(ListNode *head)
{
    if (!head)
        return true;

    ListNode *cur = head;
    ListNode *head2;
    ListNode *a = (ListNode *)new ListNode(cur->val);
    head2 = a;
    while (cur)
    {
        ListNode *b = (ListNode *)new ListNode(cur->val);
        a->next = b;
        a = b;
        cur = cur->next;
    }
    cur = reverlist(head2);

    while (cur && head)
    {
        if (cur->val != head->val)
        {
            return false;
        }
        cur = cur->next;
        head = head->next;
    }
    return true;
}