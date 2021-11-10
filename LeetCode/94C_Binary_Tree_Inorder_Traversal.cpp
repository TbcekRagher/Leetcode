#include "incl.hpp"
/// cd /mnt/c/Users/YQQ/Desktop/C++函數/LeetCode
/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Binary Tree Inorder Traversal.
Memory Usage: 8.3 MB, less than 63.97% of C++ online submissions for Binary Tree Inorder Traversal.

Time S              ubmitted    Status  RuntimeMemory   Language
09/29/2021 16:32	Accepted	0 ms	8.3 MB	        cpp
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
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
vector<int> inorderTraversal(TreeNode *root)
{
    vector<int> v;
    if (root == nullptr)
        return v;
    else if (root->left == nullptr && root->right == nullptr)
    {
        v.push_back(root->val);
        return v;
    }

    stack<TreeNode *> st;
    TreeNode *cur;
    while (root || !st.empty())
    {
        while (root)
        {
            st.push(root);
            root = root->left;
        }
        cur = st.top();
        st.pop();
        v.push_back(cur->val);
        root = cur->right;
    }
    return v;
}
int main()
{
    //ref :https://hackmd.io/@Ji0m0/B1dUOaRjN/https%3A%2F%2Fhackmd.io%2F%40Ji0m0%2FHyAgG6bU_
}