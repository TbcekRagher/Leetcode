#include<cstdio>

#include <iostream>
using namespace std;
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
struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(NULL) {}
      ListNode(int x) : val(x), next(NULL) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};
void PrintList(ListNode *p)
{
    ListNode *ptr = p;
        while(p){
            cout << p->val << "" ;
            p = p->next;
        }
        cout << endl;
}
void   invertList(ListNode** v)
{
        ListNode *n,*p,*c;
        n = NULL;
        p = *v;
        while( p!= NULL)    //  n p->c   =>  n<-p c
        {   c = p->next;
            p->next = n;
            n = p;
            p = c;
        }
        *v = n;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *v1 = l1, *v2 = l2, *v3 = NULL;
        ListNode *ptr;
        int carry = 0;
        int tmp = 0;
        int same_length = 1;
        if (!(v1 && v2))return NULL;
        //invertList(&v1);
        //invertList(&v2);
        
        //個位數
        
            if ((v1->val + v2->val) > 9)carry = 1; 
            tmp = (v1->val + v2->val) % 10;
            ptr = new ListNode(tmp,v3);
            v1 = v1->next;
            v2 = v2->next;
            v3 = ptr;
      
       
        while(v1 && v2){ 
            tmp = (v1->val + v2->val);
            tmp += carry;               //把進位加進去
            if (tmp > 9)carry = 1;
            else carry = 0;
            tmp %= 10;
            ptr = new ListNode(tmp,v3);
            v1 = v1->next;
            v2 = v2->next;
            v3 = ptr;
        }
        if (v1 != NULL){
            while(v1){
                tmp = v1->val + carry;   //把進位加進去
                if (tmp > 9)carry = 1;
                else carry = 0;
                tmp %= 10;
                ptr = new ListNode(tmp,v3);
                v3 = ptr;
                v1 = v1->next;
            }
            
        }else if (v2 != NULL){
            while(v2)
            {
                tmp = v2->val;
                tmp += carry;               //把進位加進去
                if (tmp > 9)carry = 1;
                else carry = 0;
                tmp %= 10;
                ptr = new ListNode(tmp,v3);
                v3 = ptr;
                v2 = v2->next;
            }
        }

        if (carry && !(v1 && v2)){
                ptr = new ListNode(carry,v3);
                v3 = ptr;
        }
        invertList(&v3);
        return v3;
}

int main()
{
    ListNode    *v1,*v2,*v3;
    
    ListNode* ptr;
    ptr = new ListNode(2);v1 = ptr;
    ptr = new ListNode(4,v1);v1 = ptr;
    ptr = new ListNode(3,v1);v1 = ptr;
    ptr = new ListNode(5);v2 = ptr;
    ptr = new ListNode(6,v2);v2 = ptr;
    ptr = new ListNode(4,v2);v2 = ptr;
    //個十百
    /*ptr = new ListNode(9);v1 = ptr; 
    ptr = new ListNode(9,v1);v1 = ptr;
    ptr = new ListNode(9,v1);v1 = ptr;
    ptr = new ListNode(9,v1);v1 = ptr;
    ptr = new ListNode(9,v1);v1 = ptr;
    ptr = new ListNode(9,v1);v1 = ptr;
    ptr = new ListNode(9,v1);v1 = ptr;
    
    ptr = new ListNode(9);v2 = ptr;
    ptr = new ListNode(9,v2);v2 = ptr;
    ptr = new ListNode(9,v2);v2 = ptr;
    ptr = new ListNode(9,v2);v2 = ptr;
    //PrintList(v1);
    //PrintList(v2);
    */
    v3 = addTwoNumbers(v1,v2);
    if(v3)PrintList(v3);
}