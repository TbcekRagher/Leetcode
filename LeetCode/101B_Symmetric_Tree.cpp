#include "incl.hpp"
/// cd /mnt/c/Users/YQQ/Desktop/C++函數/LeetCode
/*
Runtime: 4 ms, faster than 77.58% of C++ online submissions for Symmetric Tree.
Memory Usage: 16.4 MB, less than 41.49% of C++ online submissions for Symmetric Tree.


Time S              ubmitted    Status  RuntimeMemory   Language
10/01/2021 14:20	Accepted	4 ms	16.4 MB     	cpp
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
bool cmpsubtree(TreeNode *m, TreeNode *n)
{
    if (m == nullptr && n == nullptr)
        return true;
    else if (m == nullptr || n == nullptr)
        return false;

    //如果這兩行判斷都成功會回傳true導致if不通過直接進入return (m->val == n->val) ? true : false; 在最底層的部分
    if (!cmpsubtree(m->left, n->right))
        return false;
    if (!cmpsubtree(m->right, n->left))
        return false;
    return (m->val == n->val) ? true : false;
}
bool isSymmetric(TreeNode *root)
{
    return cmpsubtree(root, root);
}

int main()
{
    /**
     * reference : https://hackmd.io/@Ji0m0/B1dUOaRjN/https%3A%2F%2Fhackmd.io%2F%40Ji0m0%2FSynIt3jv_
     * no test .
     *
     */
}