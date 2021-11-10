/*Runtime: 8 ms, faster than 81.85% of C++ online submissions for Merge Two Sorted Lists.
 *Memory Usage: 15 MB, less than 65.42% of C++ online submissions for Merge Two Sorted Lists.
*/
#include<iostream>
#include<string>
#include<cstring>
#include<map>
#include<cstdlib>
#include<cstdio>
 using namespace std;
/*NOTE!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 *sizeof(ListNode) =  8
 *sizeof(ListNode*) = 16 
 */

/*ListNode *head = NULL is most important!!!*/
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(NULL) {}
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *head = NULL ,*tmp ;
        ListNode *current ,*t1 = l1,*t2 = l2;
        while (t1 && t2)
        {   
            current = new ListNode();
            if (!head){
                tmp = head = current;
            }
            if(!current){cerr << "allocate error " << endl; exit(0);}
            if (t1->val > t2->val){
                current ->val = t2 ->val;
                t2 = t2 ->next;
            }else{
                current ->val = t1 ->val;
                t1 = t1 ->next;
            }
            tmp -> next = current;
            tmp = current;
        }
        //head!=NULL tmp must not be NULL as well
        if(t1){
            if (!head){
                head = t1;
            }else tmp ->next = t1;
        }else if (t2){
            if (!head){
                head = t2;
            }else tmp ->next = t2;
        } 
        return head;
}
int main()
{
    ListNode* l1 = NULL; 
    ListNode* l2 =  new ListNode(0,NULL);
    ListNode* t1 = l1,*t2 = l2,*current ;

    //current =  mergeTwoLists(l1,l2);
    cout << sizeof(l2) <<endl;
}