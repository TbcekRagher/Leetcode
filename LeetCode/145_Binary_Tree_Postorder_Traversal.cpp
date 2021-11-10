#include "incl.hpp"

/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Binary Tree Postorder Traversal.
Memory Usage: 8.4 MB, less than 63.34% of C++ online submissions for Binary Tree Postorder Traversal.
Next challenges:
Time S              ubmitted    Status  RuntimeMemory   Language
10/13/2021 00:52	Accepted	0 ms	8.4 MB	        cpp
*/

/*
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
void __postorderTraversal(TreeNode *root, vector<int> &v)
{
    if (root)
    {
        __postorderTraversal(root->left, v);
        __postorderTraversal(root->right, v);
        v.push_back(root->val);
    }
}
vector<int> postorderTraversal(TreeNode *root)
{
    vector<int> v;
    if (!root)
        return v;

    __postorderTraversal(root, v);
    return v;
}
