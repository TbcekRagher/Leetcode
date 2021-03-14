/*Runtime: 32 ms, faster than 63.74% of C++ online submissions for Add Two Numbers.
 *Memory Usage: 71.2 MB, less than 67.58% of C++ online submissions for Add Two Numbers.
 */

/*Input: l1 = [2,4,3], l2 = [5,6,4]
*Output: [7,0,8]
*Explanation: 342 + 465 = 807.
*Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
*Output: [8,9,9,9,0,0,0,1]
*Input: l1 = [0], l2 = [0]
*Output: [0]
*/

#include<iostream>
#include<string>
using namespace std;
struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(NULL) {}
      ListNode(int x) : val(x), next(NULL) {}//nullptr
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
        int same_length = 1;    //judge
        if (!(v1 && v2))return NULL;
        //invertList(&v1);
        //invertList(&v2);

        //個位數
            if ((v1->val + v2->val) > 9)carry = 1; //a + b >10 ;c=1;
            tmp = (v1->val + v2->val) % 10;        //tmp = 9 ex 19-10=9
            ptr = new ListNode(tmp,v3);            // create tmpty block
            v1 = v1->next;
            v2 = v2->next;
            v3 = ptr;                              //ptr ->v3  ->NULL

        while(v1 && v2){ 
            tmp = (v1->val + v2->val);
            tmp += carry;               //add the carry，no matter 1 or 0.
            if (tmp > 9)carry = 1;      //judge carry 
            else carry = 0;
            tmp %= 10;
            ptr = new ListNode(tmp,v3);
            v1 = v1->next;
            v2 = v2->next;
            v3 = ptr;
        }
        //
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

        if (carry && !(v1 && v2))   //the last step 9+1 = 10 induce carry ,create a new block
        {
                ptr = new ListNode(carry,v3);
                v3 = ptr;
        }
        invertList(&v3);
        return v3;
}

