#include "incl.hpp"
//faster sol
/* ###My method is worst of all sol
Runtime: 35 ms, faster than 5.36% of C++ online submissions for Linked List Cycle.
Memory Usage: 11.2 MB, less than 6.92% of C++ online submissions for Linked List Cycle.


Time S              ubmitted    Status  RuntimeMemory   Language
10/11/2021 17:23	Accepted	35 ms	11.2 MB	        cpp


You must implement a solution with a linear runtime complexity and use only constant extra space.
*/

/
    /**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
    struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
bool hasCycle(ListNode *head)
{
    if (!head || !head->next)
        return false;
    set<ListNode *> s;
    s.insert(head);
    head = head->next;
    while (head)
    {
        if (s.find(head) == s.end() - 1)
        {
            s.insert(head);
        }
        else
        {
            return true;
        }
        head = head->next;
    }
    return false;
}

int main()
{
    /*###
    Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.
    Given head, the head of a linked list, determine if the linked list has a cycle in it.
    There is a cycle in a linked list if there is some node in the list that can be reached again by continuously
    following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.
    Return true if there is a cycle in the linked list. Otherwise, return false.


    Example 1:
    Input: head = [3,2,0,-4], pos = 1
    Output: true
    Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).

    Example 2:
    Input: head = [1,2], pos = 0
    Output: true
    Explanation: There is a cycle in the linked list, where the tail connects to the 0th node.

    Example 3:
    Input: head = [1], pos = -1
    Output: false
    Explanation: There is no cycle in the linked list.
    */
}