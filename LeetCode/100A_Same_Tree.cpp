/*Best sol
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Same Tree.
Memory Usage: 10.1 MB, less than 45.76% of C++ online submissions for Same Tree.
*/

bool isSameTree(TreeNode *p, TreeNode *q)
{
    if (!p && !q)
        return true;
    if (!p || !q)
        return false;
    if (p->val != q->val)
        return false;
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

#include "incl.hpp"
/// cd /mnt/c/Users/YQQ/Desktop/C++函數/LeetCode
/*
Runtime: 4 ms, faster than 44.58% of C++ online submissions for Same Tree.
Memory Usage: 10.2 MB, less than 7.52% of C++ online submissions for Same Tree.

Time S              ubmitted    Status  RuntimeMemory   Language
09/30/2021 15:22	Accepted	4 ms	10.2 MB	        cpp
*/

/** my sol
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

bool isSameTree(TreeNode *p, TreeNode *q)
{
    if (p == nullptr && q == nullptr)
        return true;
    else if (p == nullptr)
        return false;
    else if (q == nullptr)
        return false;

    queue<TreeNode *> q1;
    queue<TreeNode *> q2;
    TreeNode *pcur, *qcur;
    q1.push(p);
    q2.push(q);
    while (!q1.empty() && !q2.empty())
    {
        pcur = q1.front();
        qcur = q2.front();
        q1.pop();
        q2.pop();
        if (pcur->val != qcur->val) //先判斷現在的currnoe 兩個是否同值
            return false;
        if (pcur->left && qcur->left)
        {
            q1.push(pcur->left);
            q2.push(qcur->left);
        }
        else if ((!pcur->left && qcur->left) || (pcur->left && !qcur->left))
        {
            return false;
        }

        if (pcur->right && qcur->right)
        {
            q1.push(pcur->right);
            q2.push(qcur->right);
        }
        else if ((!pcur->right && qcur->right) || (pcur->right && !qcur->right))
        {
            return false;
        }
    }
    if (!q1.empty() && q2.empty())
        return false;
    else if (q1.empty() && !q2.empty())
        return false;
    return true;
}

/*
Runtime: 4 ms, faster than 44.58% of C++ online submissions for Same Tree.
Memory Usage: 9.9 MB, less than 95.70% of C++ online submissions for Same Tree.
*/

bool isSameTree(TreeNode *p, TreeNode *q)
{
    if (p == nullptr || q == nullptr)
        return p == q;
    return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

/*crate tree;*/
bool all_number(string &s)
{
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] < '0' || s[i] > '9')
            return false;
    }
}

TreeNode *create_Tree_from_StringArray(const String *&a[]) //還沒test
{                                                          /*()
    Input: p = [1,2,3], q = [1,2,3]
    Output: true

    Input: p = [1,2], q = [1,null,2]
    Output: false
    */
    int n = a.length();
    if (n == 0)
    {
        cout << "create invaild" << endl;
        cerr << "Line = " << __LINE__ << "   function = " << __FUNCTIONW__ << endl;
        exit(0);
    }
    queue<TreeNode *> q;
    TreeNode *root = (TreeNode *)new TreeNode(a[0]);
    TreeNode *curr;
    q.push(root);
    for (int i = 1; i < n;)
    {
        if (q.empty())
        {
            cout << "st stept create invaild" << endl;
            cerr << "Line = " << __LINE__ << "   function = " << __FUNCTIONW__ << endl;
            exit(0);
        }
        curr = q.pop();
        q.pop();
        if (a[i] == 'null')
        {
            curr->left = nullptr;
        }
        else if (all_number(a[i]))
        {

            TreeNode *left = (TreeNode *)new TreeNode(atoi(a[i]););
            curr->left = left;
            q.push(left);
        }
        i++;
        if (a[i] == 'null')
        {
            curr->right = nullptr;
        }
        else if (all_number(a[i]))
        {

            TreeNode *right = (TreeNode *)new TreeNode(atoi(a[i]););
            curr->right = right;
            q.push(right);
        }
        i++;
    }
}
int main()
{
    /*()
    Input: p = [1,2,3], q = [1,2,3]
    Output: true

    Input: p = [1,2], q = [1,null,2]
    Output: false
    */
    //this problem NO test ,but directly summit
}

/*python
  # Iterative DFS
    def isSameTree(self, p: TreeNode, q: TreeNode) -> bool:
        stack = [(p, q)]
        max_stack_size = 0
        while stack:
            max_stack_size = max(max_stack_size, len(stack))
            p, q = stack.pop()
            if not p and not q:
                continue
            elif (not p or not q) or (p.val != q.val):
                return False
            stack.extend([(p.right, q.right), (p.left, q.left)])
        print(max_stack_size)
        return True

    # Iterative BFS
    def isSameTree(self, p: TreeNode, q: TreeNode) -> bool:
        queue = collections.deque([(p, q)])
        max_queue_size = 0
        while queue:
            max_queue_size = max(max_queue_size, len(queue))
            p, q = queue.popleft()
            if not p and not q:
                continue
            elif (not p or not q) or (p.val != q.val):
                return False
            queue.extend([(p.left, q.left), (p.right, q.right)])
        print(max_queue_size)
        return True

# Fully Skewed
[1,2,null,3,null,4,null,5,null,6,null,7,null,8,null,9,null,10,null,11,null,12,null,13,null,14,null,15]
[1,2,null,3,null,4,null,5,null,6,null,7,null,8,null,9,null,10,null,11,null,12,null,13,null,14,null,15]
# Results:
# max_stack_size == 16
# max_queue_size == 3


# Perfectly Balanced
[1,2,3,4,5,6,7,8,9,10,11,12,13,14,15]
[1,2,3,4,5,6,7,8,9,10,11,12,13,14,15]
# Results:
# max_stack_size == 5
# max_queue_size == 16
*/