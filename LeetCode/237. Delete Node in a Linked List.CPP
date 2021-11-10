
#include "incl.hpp"

/*這個算是一次救過，然後完全沒有test  我超猛的拉
Runtime: 12 ms, faster than 82.66% of C++ online submissions for Delete Node in a Linked List.
Memory Usage: 7.6 MB, less than 38.00% of C++ online submissions for Delete Node in a Linked List.
Time S              ubmitted    Status  RuntimeMemory   Language
11/10/2021 16:37	Accepted	12 ms	7.6 MB	cpp
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*
Write a function to delete a node in a singly-linked list. You will not be given access to the head of the list,
instead you will be given access to the node to be deleted directly.
It is guaranteed that the node to be deleted is not a tail node in the list.
*/

/*better than my self
void deleteNode(ListNode* node) {
        node->val=node->next->val; //copying node's next value
       node->next=node->next->next; //connect by skipping one node
    }

*/
void deleteNode(ListNode *node)
{
    if (!node)
        return;
    while (node->next->next) //要確保後兩手不是尾巴
    {
        node->val = node->next->val;
        node = node->next;
    }
    node->val = node->next->val;
    node->next = nullptr;
}
