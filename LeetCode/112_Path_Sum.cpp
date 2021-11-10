#include "incl.hpp"

/// cd /mnt/c/Users/YQQ/Desktop/C++函數/LeetCode
/*
Runtime: 16 ms, faster than 30.26% of C++ online submissions for Path Sum.
Memory Usage: 21.5 MB, less than 32.86% of C++ online submissions for Path Sum.

Time S              ubmitted    Status  RuntimeMemory   Language
10/06/2021 13:41	Accepted	16 ms	21.5 MB	        cpp
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
bool __hasPathSum(TreeNode *root, int targetSum)
{
    if (!root)
        return false;
    if (__hasPathSum(root->left, targetSum - root->val))
        return true;

    if (__hasPathSum(root->right, targetSum - root->val))
        return true;

    if (!root->left && !root->right)
    {
        if (root->val == targetSum)
            return true;
        else
            return false;
    }
    return false;
}
bool __hasPathSum(TreeNode *root, int targetSum)
{
    if (!root)
        return false;
    if (root->left)
    {
        if (__hasPathSum(root->left, targetSum - root->val))
            return true;
    }
    if (root->right)
    {
        if (__hasPathSum(root->right, targetSum - root->val))
            return true;
    }

    if (!root->left && !root->right)
    {
        if (root->val == targetSum)
            return true;
        else
            return false;
    }
    return false;
}
bool hasPathSum(TreeNode *root, int targetSum)
{
    if (!root)
        return false;

    if (!root->left && !root->right)
    {
        if (root->val == targetSum)
            return true;
        else
            return false;
    }
    return __hasPathSum(root->left, targetSum - root->val) || __hasPathSum(root->right, targetSum - root->val);
}

int main()
{
    /*
        It's done without any reference,I am excited about the result,so I record this exciting moment
    */
}