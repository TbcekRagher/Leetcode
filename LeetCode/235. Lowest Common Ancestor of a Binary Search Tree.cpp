#include "incl.hpp"

/*這個算是一次救過，然後完全沒有test  我超猛的拉
Runtime: 28 ms, faster than 83.35% of C++ online submissions for Lowest Common Ancestor of a Binary Search Tree.
Memory Usage: 23.2 MB, less than 92.61% of C++ online submissions for Lowest Common Ancestor of a Binary Search Tree.
Time S              ubmitted    Status  RuntimeMemory   Language
11/09/2021 18:26	Accepted	28 ms	23.2 MB	        cpp
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/*other answer
Runtime: 28 ms, faster than 83.35% of C++ online submissions for Lowest Common Ancestor of a Binary Search Tree.
Memory Usage: 23.2 MB, less than 61.88% of C++ online submissions for Lowest Common Ancestor of a Binary Search Tree.
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode *temp=root;
        while(temp)
        {
            if((temp->val<=p->val && temp->val>=q->val) || (temp->val>=p->val && temp->val<=q->val))
                return temp;
            else if(temp->val<p->val && temp->val<q->val)
                temp=temp->right;
            else if(temp->val>p->val && temp->val>q->val)
                temp=temp->left;
        }
        return temp;
    }
*/
TreeNode *BstSearchNode(TreeNode *root, int val)
{ //還沒測試過
    if (root)
    {
        if (root->val == val)
        {
            return root;
        }
        else if (root->val > val)
        {
            return BstSearchNode(root->left, val);
        }
        else
        {
            return BstSearchNode(root->right, val);
        }
    }
}
bool BstSearchNode(TreeNode *root, TreeNode *tar)
{ //還沒測試過
    if (root)
    {
        if (root->val == tar->val)
        {
            return true;
        }
        else if (root->val > tar->val)
        {
            return BstSearchNode(root->left, tar);
        }
        else
        {
            return BstSearchNode(root->right, tar);
        }
    }
    return false;
}

TreeNode *__lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (root)
    {

        if ((root->val > p->val) && (root->val > q->val)) // 皆在root 左邊
        {
            return __lowestCommonAncestor(root->left, p, q);
        }
        else if ((root->val < p->val) && (root->val < q->val)) // 皆在root 右邊{
        {
            return __lowestCommonAncestor(root->right, p, q);
        }
        else if (((root->val < p->val) && (root->val > q->val)) || ((root->val > p->val) && (root->val < q->val))) //一個在root左邊一個在root右邊 那就是root
        {
            return root;
        }
    }
    return nullptr;
}

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (!root)
        return root;

    if (BstSearchNode(p, q))
    {
        return p;
    }
    if (BstSearchNode(q, p))
    {
        return q;
    }
    return __lowestCommonAncestor(root, p, q);
}