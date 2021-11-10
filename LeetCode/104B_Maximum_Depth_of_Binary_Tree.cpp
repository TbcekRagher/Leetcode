#include "incl.hpp"
/// cd /mnt/c/Users/YQQ/Desktop/C++函數/LeetCode
/*
Runtime: 12 ms, faster than 36.52% of C++ online submissions for Maximum Depth of Binary Tree.
Memory Usage: 18.9 MB, less than 55.00% of C++ online submissions for Maximum Depth of Binary Tree.


Time S              ubmitted    Status  RuntimeMemory   Language
10/02/2021 15:17	Accepted	12 ms	18.9 MB	        cpp
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
inline int max(int a, int b)
{
    return (a > b) ? a : b;
}
int maxDepth(TreeNode *root)
{
    if (!root)
        return 0;
    return (max(maxDepth(root->left), maxDepth(root->right))) + 1
}