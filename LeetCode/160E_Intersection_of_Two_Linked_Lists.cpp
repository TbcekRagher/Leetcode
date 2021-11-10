#include "incl.hpp"

/*
Time S              ubmitted    Status  RuntimeMemory   Language
10/15/2021 14:23	Accepted	51 ms	14.7 MB	cpp
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    if (headA && !headB)
        return nullptr;
    if (!headA && headB)
        return nullptr;

    ListNode *ptr1 = headA;
    ListNode *ptr2 = headB;

    while (ptr1 != ptr2)
    {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;

        if (!ptr1 && !ptr2)
            break;
        if (!ptr1)
        {
            ptr1 = headB;
        }
        if (!ptr2)
        {
            ptr2 = headA;
        }
    }

    return ptr1;
}
int main()
{
    // ref ::https://leetcode.com/problems/intersection-of-two-linked-lists/discuss/1521673/C%2B%2B-10-line-code-simple-solution
}
