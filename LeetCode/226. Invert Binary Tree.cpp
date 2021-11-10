
#include "incl.hpp"

/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Invert Binary Tree.
Memory Usage: 9.7 MB, less than 79.92% of C++ online submissions for Invert Binary Tree.
Time S              ubmitted    Status  RuntimeMemory   Language
11/02/2021 13:53	Accepted	0 ms	9.7 MB      	cpp
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

void __inverTree(TreeNode *root)
{
    if (root)
    {
        TreeNode *curr = root->left;
        root->left = root->right;
        root->right = curr;
        if (root->left)
        {
            __invertTree(root->left);
        }
        if (root->right)
        {
            __invertTree(root->right);
        }
    }
}
TreeNode *invertTree(TreeNode *root)
{
    if (!root)
        return root;
    __inverTree(root);
    return root;
}