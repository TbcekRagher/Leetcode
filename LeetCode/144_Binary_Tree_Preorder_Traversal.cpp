#include "incl.hpp"

/*
Runtime: 4 ms, faster than 44.79% of C++ online submissions for Binary Tree Preorder Traversal.
Memory Usage: 8.5 MB, less than 16.69% of C++ online submissions for Binary Tree Preorder Traversal.
Time S              ubmitted    Status  RuntimeMemory   Language
10/12/2021 15:46	Accepted	4 ms	8.5 MB	        cpp
*/

/**
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

vector<int> preorderTraversal(TreeNode *root)
{
    vector<int> v;
    if (!root)
    {
        return v;
    }
    stack<TreeNode *> s;
    TreeNode *cur = root;
    s.push(root);
    while (!s.empty() && cur)
    {
        v.push_back(cur->val);
        if (cur->left)
        {
            if (cur->right)
            {
                s.push(cur->right);
            }
            cur = cur->left;
        }
        else if (cur->right)
        {
            cur = cur->right;
        }
        else
        {
            cur = s.top();
            s.pop();
        }
    }
    return v;
}
