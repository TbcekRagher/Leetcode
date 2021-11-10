#include "incl.hpp"

/// cd /mnt/c/Users/YQQ/Desktop/C++函數/LeetCode
//https://stackoverflow.com/questions/10033373/c-error-nullptr-was-not-declared-in-this-scope-in-eclipse-ide
// 解決null無法編譯的問題 g++ -std=c++0x *.cpp -o output\
//#compile use  :  g++ -std=c++0x 83_Remove_Duplicates_from_Sorted_List.cpp

/*
Runtime: 8 ms, faster than 88.47% of C++ online submissions for Remove Duplicates from Sorted List.
Memory Usage: 11.5 MB, less than 76.96% of C++ online submissions for Remove Duplicates from Sorted List.
Time S              ubmitted    Status  RuntimeMemory   Language
09/27/2021 19:18	Accepted	8 ms	11.5 MB	        cpp
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

ListNode *deleteDuplicates1(ListNode *head) //允許操作記憶體的作法,處理亂數可以用
{
    set<int> myset;
    ListNode *curr = head;
    while (curr->next != nullptr)
    {
        myset.insert(curr->get_val());
        curr = curr->next;
    }
    curr = head->next;

    free(curr);
    curr = head;

    for (set<int>::iterator it = myset.begin(); it != myset.end(); it++)
    {
        ListNode *ptr = (ListNode *)new ListNode(*it);
        curr->next = ptr;
        curr = ptr;
    }
    head = head->next;
    return head;
}

int main()
{
    ListNode *head = (ListNode *)new ListNode(0);
    ListNode *curr = head;
    int n = 0;
    for (int i = 1; i < 20; i++)
    {
        if (i < 5)
            n = 20;
        else if (i < 10 && i > 5)
            n = 10;
        else if (i < 15 && i > 10)
            n = 30;
        else
            n = 20;
        ListNode *ptr = (ListNode *)new ListNode(n);
        // if (((ptr->get_val()) % 2) == 1)ptr->set_val(i - 50);
        curr->next = ptr;
        curr = ptr;
    }
    head->print_list();
    head = deleteDuplicates_for_random_odrer(head);
    head->print_list();
}

/*
*/