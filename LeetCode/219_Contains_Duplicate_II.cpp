
#include "incl.hpp"

/*
Runtime: 164 ms, faster than 75.06% of C++ online submissions for Contains Duplicate II.
Memory Usage: 76.9 MB, less than 75.74% of C++ online submissions for Contains Duplicate II.
Time S              ubmitted    Status  RuntimeMemory   Language
10/24/2021 12:46	Accepted	164 ms	76.9 MB	        cpp
*/
/*雙for 不合格
bool containsNearbyDuplicate(vector<int> &nums, int k)
{
    int n = nums.size();
    if (n == 0 || n == 1)
        return false;
    else if (n == 2)
        return ((nums[0] == nums[1]) ? true : false);

    for (int i = 0; i < n; i++)
    {
        int j = i + 1;
        while ((j - i) <= k && j < n)
        {
            if (nums[i] == nums[j++])
                return true;
        }
    }
    return false;
}
*/
bool containsNearbyDuplicate(vector<int> &a, int k)
{
    unordered_map<int, int> m; //<a[i],index>
    int i = 0;
    for (auto ai : a)
    {
        if (m.count(ai)) //如果找到
        {
            if (abs(m[ai] - i) <= k) //現在的i與其插有沒有小於k
                return true;
            m[ai] = i; //超過k了重新設定 ai 的index
        }
        else
        {
            m[ai] = i; //unorder_map 增加元素的方式
        }
        i++;
    }
    return false;
}
int main()
{
    int a[] = {1, 2, 3, 1};
    int len = sizeof(a) / sizeof(int);
    vector<int>
        v = arr_to_vector(a, len);

    cout << (bool)containsNearbyDuplicate(v, 3) << endl;
    /*
    Easy
[99,99]
2
Given an integer array nums and an integer k, return true if there are two distinct indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k.
Example 1:

Input: nums = [1,2,3,1], k = 3
Output: true
Example 2:

Input: nums = [1,0,1,1], k = 1
Output: true
Example 3:

Input: nums = [1,2,3,1,2,3], k = 2
Output: false
*/
}
