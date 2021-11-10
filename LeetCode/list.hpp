#include <set>
#include <iostream>
#include <iterator>
using namespace std;
/*-----   class ListNode-----------------------------------*/
class ListNode
{
    int val;

public:
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
    ListNode *next;

    void print_list()
    {
        ListNode *curr = this;
        while (curr->next != nullptr)
        {
            cout << curr->val << " ";
            curr = curr->next;
        }
        cout << endl;
    }
    void set_val(int n)
    {
        this->val = n;
    }
    int get_val()
    {
        return this->val;
    }
};

/*---------------other function of the Listnode--------------------*/
void __error(string error_msg)
{
    throw invalid_argument(error_msg);
}

void removeElement(ListNode *pre, ListNode *curr)
{
    if (pre && curr)
    {
        ListNode *ptr = curr;
        pre->next = curr->next;
        curr = curr->next;
        delete (ptr);
    }
    else
        __error("the pre or curr ListNode is null");
}

/*------Leetcode problem sol  function -------------*/
ListNode *deleteDuplicates_for_well_ordering(ListNode *head) //for 有敘數列可以用， 1,2,2,3,3,3,4,5,6這種的,  阿如果是1,3,3,2,3這種就要用下面的
{
    if (head == nullptr || head->next == nullptr)
        return head;
    ListNode *curr = head;
    while (curr->next != nullptr)
    {
        if (curr->get_val() == curr->next->get_val())
            curr->next = curr->next->next;
        else
            curr = curr->next;
    }
    return head;
}
ListNode *deleteDuplicates_for_random_odrer(ListNode *head) //允許操作記憶體的作法,處理亂數可以用
{
    set<int> myset;
    ListNode *curr = head;
    ListNode *prev = head;
    myset.insert(curr->get_val());
    curr = curr->next;

    while (curr->next != nullptr)
    {
        if ((myset.find(curr->get_val())) != myset.end()) //find沒找到會回傳end();
        {
            prev->next = curr->next;
            ListNode *ptr = curr;
            curr = curr->next;
            free(ptr);
            continue;
        }
        myset.insert(curr->get_val());
        prev = curr;
        curr = curr->next;
    }
    return head;
}
/*test coed
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
    head = deleteDuplicates2(head);
    head->print_list();
    */