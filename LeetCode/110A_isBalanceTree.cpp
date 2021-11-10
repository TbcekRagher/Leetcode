#include "incl.hpp"
/// cd /mnt/c/Users/YQQ/Desktop/C++函數/LeetCode
/*
Runtime: 12 ms, faster than 64.39% of C++ online submissions for Balanced Binary Tree.
Memory Usage: 20.9 MB, less than 80.62% of C++ online submissions for Balanced Binary Tree.


Time S              ubmitted    Status  RuntimeMemory   Language
10/04/2021 14:35	Accepted	12 ms	20.9 MB	        cpp
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
bool f = false; //f = true 表示已經掛了
int __isBalance(TreeNode *root, bool &out)
{
    if (!root || f) //一開始f尚未被設定，所以會直接走到左底
        return 0;
    int l = __isBalance(root->left);
    int r = __isBalance(root->right);
    if (abs(l - r) > 1)
        f = true;
    return max(l, r) + 1;
}
bool isBalanced(TreeNode *root)
{
    __isBalance(root);
    return !f;
}

/*這個跑得比較慢，但有點特別
 pair<int, bool> dfs(TreeNode* root){
        if(root == NULL)
            return {0, true};

        auto [leftH, leftB] = dfs(root->left);
        auto [rightH, rightB] = dfs(root->right);

        if(abs(leftH - rightH) > 1)
            return {1 + max(leftH, rightH), false};
        else
            return {1 + max(leftH, rightH), leftB && rightB};//基本上只要過程中有一個false就永遠都會是false，這段算是相當步錯
    }
public:
    bool isBalanced(TreeNode* root) {
        return dfs(root).second;
    }
*/
int main()
{ /*reference https://leetcode.com/problems/balanced-binary-tree/discuss/1494437/c%2B%2B-or-100-faster-or-recursion-or-easy
    int a[] = {0, 1, 2, 3, 4, 5, 6};
    vector<int> v;
    v.assign(a, a + (sizeof(a) / sizeof(int)));
    TreeNode *root = sortedArrayToBST(v);
    inorder(root);
    if (isBalanced(root))
        cout << "true" << endl;
    else
        cout << "false" << endl;
    */
}
