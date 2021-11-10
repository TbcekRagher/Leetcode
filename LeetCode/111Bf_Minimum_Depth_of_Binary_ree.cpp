#include "incl.hpp"

/// cd /mnt/c/Users/YQQ/Desktop/C++函數/LeetCode
/*
Runtime: 12 ms, faster than 64.39% of C++ online submissions for Balanced Binary Tree.
Memory Usage: 20.9 MB, less than 80.62% of C++ online submissions for Balanced Binary Tree.


Time S              ubmitted    Status  RuntimeMemory   Language
10/04/2021 14:35	Accepted	12 ms	20.9 MB	        cpp
*/
/*The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

Note: A leaf is a node with no children.*/
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

/*other faster
Runtime: 208 ms, faster than 96.31% of C++ online submissions for Minimum Depth of Binary Tree.
Memory Usage: 144.9 MB, less than 24.72% of C++ online submissions for Minimum Depth of Binary Tree.
int calc(TreeNode *root)
 {
     if(root->left==NULL&&root->right==NULL)
        return 1;
     else if(root->left==NULL)
     {
         return 1+calc(root->right);
     }
    else if(root->right==NULL)
     {
         return 1+calc(root->left);
     }
     else{
     return 1+min(calc(root->left),calc(root->right));
     }
 }
int minDepth(TreeNode* root) {
if(root==NULL)
    return 0;

    return calc(root);
*/
//---------------------------------------
/*
Runtime: 339 ms, faster than 24.60% of C++ online submissions for Minimum Depth of Binary Tree.
Memory Usage: 144.7 MB, less than 42.56% of C++ online submissions for Minimum Depth of Binary Tree.
int minDepth(TreeNode *root)
{

    if (!root)
        return 0;
    int l = minDepth(root->left);
    int r = minDepth(root->right);
    if (!root->right || !root->left)
        return max(l, r) + 1;

    return min(l, r) + 1;
}*/

/*弄錯題目意思的
int minheight_of_sub_tree(TreeNode *root)//在BST中算最少的Depth
{
    if (!root)
        return 0;
    int n = 0;
    queue<TreeNode *> q;
    TreeNode *curr = root;
    q.push(root);
    while (curr && !q.empty())
    {
        curr = q.front();
        q.pop();
        if (curr->left && curr->right)
        {
            q.push(curr->left);
            q.push(curr->right);
            n++;
        }
        else
            return int(log2(n));
    }
}
*/