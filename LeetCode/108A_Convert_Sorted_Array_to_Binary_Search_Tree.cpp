#include "incl.hpp"
/// cd /mnt/c/Users/YQQ/Desktop/C++函數/LeetCode
/*
Runtime: 12 ms, faster than 77.53% of C++ online submissions for Convert Sorted Array to Binary Search Tree.
Memory Usage: 21.5 MB, less than 44.12% of C++ online submissions for Convert Sorted Array to Binary Search Tree.


Time S              ubmitted    Status  RuntimeMemory   Language
10/03/2021 19:20	Accepted	12 ms	21.5 MB	        cpp
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

/*need balance*/
TreeNode *__sortArrayToBst(vector<int> &nums, int start, int end)
{
    if (start >= end)
        return nullptr;
    int mid = (start + end) / 2;
    TreeNode *root = (TreeNode *)new TreeNode(nums[mid]);
    root->left = __sortArrayToBst(nums, start, mid);
    root->right = __sortArrayToBst(nums, mid + 1, end);
    return root;
}
TreeNode *sortedArrayToBST(vector<int> &nums)
{
    int n = nums.size();
    if (n == 0)
        return nullptr;
    return __sortArrayToBst(nums, 0, n);
}
void preorder(TreeNode *root)
{
    if (root)
    {
        preorder(root->left);

        cout << root->val << " ";

        preorder(root->right);
    }
}
int main()
{ /*reference https://hackmd.io/@Ji0m0/B1dUOaRjN/https%3A%2F%2Fhackmd.io%2F%40Ji0m0%2FSkL6lS-Ku
    int a[] = {0, 1, 2, 3, 4, 5};
    vector<int> v;
    v.assign(a, a + (sizeof(a) / sizeof(int)));
    TreeNode *root = sortedArrayToBST(v);
    preorder(root);
    cout << endl;
}

/*這個寫法不平衡
void TreeNode_insert(TreeNode *root, int s)
{
    if (root)
    {
        cout << "s " << s << endl;
        if (s >= root->val)
        {
            if (root->right)
            {
                TreeNode_insert(root->right, s);
            }
            else
            {
                TreeNode *cur = (TreeNode *)new TreeNode(s);
                root->right = cur;
            }
        }
        else
        { //s   < root->val
            if (root->left)
            {
                TreeNode_insert(root->left, s);
            }
            else
            {
                TreeNode *cur = (TreeNode *)new TreeNode(s);
                root->left = cur;
            }
        }
    }
}
TreeNode *sortedArrayToBST(vector<int> &nums)
{
    int n = nums.size(); //vector 可以用size來取元素個素。
    if (n == 0)
        return nullptr;
    cout << "n = " << n << endl;
    int i = 0;

    TreeNode *root = (TreeNode *)new TreeNode(nums[n / 2]);
    cout << root->val << endl;
    while (i < n)
    {
        if (nums[i] == root->val)
        {
            i++;
            continue;
        }
        TreeNode_insert(root, nums[i]);
        i++;
    }
    return root;
}
*/