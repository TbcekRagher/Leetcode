
#include "incl.hpp"

/*
without inline
Runtime: 20 ms, faster than 87.16% of C++ online submissions for Remove Linked List Elements.
Memory Usage: 15.1 MB, less than 44.14% of C++ online submissions for Remove Linked List Elements.
Time S              ubmitted    Status  RuntimeMemory   Language
10/30/2021 12:16	Accepted	20 ms	15.1 MB	        cpp
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
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


ListNode *removeElements(ListNode *head, int val)
{

    if (head)
    {
        while (head)
        {
            if (head->val == val)
                head = head->next;
            else
                break;
        }
        if (!head) //for the condition that the list has been all deleted.
            return nullptr;

        //come to here I make sure that the head->val is not equal to the val.
        ListNode *pre = head;
        ListNode *curr = head->next;

        while (curr)
        {
            if (curr->val == val)
            {
                ListNode *ptr = curr;
                pre->next = curr->next;
                curr = curr->next;
                delete (ptr);
                continue;
            }
            pre = curr;
            curr = curr->next;
        }
    }
    return head;
}
