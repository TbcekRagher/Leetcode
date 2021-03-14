#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
#define STACK_SIZE 100
#define STACK_PART1 1
#define STACK_PART2 2
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next() {}
    ListNode(int x) : val(x), next() {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
void    invertList(ListNode** v)
{
        ListNode *n,*p,*c;
        n = NULL;
        p = *v;
        while(p != NULL)
        {   c = p->next;
            p->next = n;
            n = p;
            p = c;
        }
        *v = p;
} 
 
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

void push(int *s, int item,int *top, int st_part)
{  if(st_part == STACK_PART1)
    {
        if(*top > STACK_SIZE/2){cerr<<"stack is full----invalid" << endl;}
    }else if (st_part == STACK_PART2){
        if(*top > STACK_SIZE){cerr << "stack is full----invalid" << endl;}
    }
    s[++(*top)] = item;
}
int pop(int *s, int *top, int st_part)
{   
    if(*top >= 0 )
    return s[(*top)--];
    else 
        cerr <<"stack is empty----invalid"<< endl;
        
}
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *v1 = l1,  *v2 = l2 ;
        //implemt by the stack
        int carry ; int stack[100+1];
        int *top1 ; *top1 = -1;//0~49
        int *top2 ; *top2 = STACK_SIZE/2;
        while(v1 != NULL){
            v1 = v1 -> next; 
            push(stack,v1->val,top1,STACK_PART1);
        }
        while(v2 != NULL){
            v2 = v2 -> next;
            push(stack,v2->val,top2,STACK_PART2);
        }
        
        
            
    }
};

