#include <iostream>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
/*
class TreeNode_cls
{
public:
    int val;
    TreeNode_cls *left;
    TreeNode_cls *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
*/
void preorder(TreeNode *root)
{
    if (root)
    {
        cout << root->val << " ";
        preorder(root->left);
        preorder(root->right);
    }
}
void inorder(TreeNode *root)
{
    if (root)
    {
        preorder(root->left);

        cout << root->val << " ";

        preorder(root->right);
    }
}
void postrder(TreeNode *root)
{
    if (root)
    {
        preorder(root->left);

        preorder(root->right);
        std::cout << root->val << " ";
    }
}
/* balance  can be Template T  is design for interge or single string,It haven't been test on matrix yet*/
// 1.sortArrayToBst
template <typename T>
TreeNode *__sortArrayToBst(vector<T> &nums, int start, int end)
{
    if (start >= end)
        return nullptr;
    int mid = (start + end) / 2;
    TreeNode *root = (TreeNode *)new TreeNode(nums[mid]);
    root->left = __sortArrayToBst(nums, start, mid);
    root->right = __sortArrayToBst(nums, mid + 1, end);
    return root;
}
template <typename T>
TreeNode *sortedArrayToBST(vector<T> &nums)
{
    int n = nums.size();
    if (n == 0)
        return nullptr;
    return __sortArrayToBst(nums, 0, n);
}
/*-----------Leetcode sol function------*/
template <typename T>
void Bst_insert_View_0_As_NULL(TreeNode *root, T val)
{

    if (root)
    {
        if (val == 0)
        {
        }
        else if (root->val < val)
        {
            Bst_insert_View_0_As_NULL(root->left, val);
        }
        else
            Bst_insert_View_0_As_NULL(root->right, val);
    }
    else
    {
        TreeNode *curr = (TreeNode *)new TreeNode(val);
    }
}
template <typename T>
TreeNode *ArrayToBST_View_0_As_NULL(vector<T> &nums) //未完成
{
    int n = nums.size();
    int i = 1;
    if (n == 0)
        return nullptr;
    TreeNode *root = (TreeNode *)new TreeNode(nums[0]);
}
