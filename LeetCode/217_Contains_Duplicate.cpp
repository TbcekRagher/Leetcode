#include "incl.hpp"

/*
Runtime: 51 ms, faster than 25.81% of C++ online submissions for Contains Duplicate.
Memory Usage: 21.1 MB, less than 22.97% of C++ online submissions for Contains Duplicate.
Time S              ubmitted    Status  RuntimeMemory   Language
10/23/2021 18:56	Accepted	51 ms	21.1 MB	        cpp
*/
bool containsDuplicate_3(vector<int> &nums)
{
    set<int> sets;
    for (auto i : nums)
        sets.insert(i);
    return nums.size() == sets.size() ? false : true;
}

bool containsDuplicate(vector<int> &nums)
{
    int n = nums.size();
    if (n == 0 || n == 1)
        return false;
    else if (n == 2)
        return (nums[0] == nums[1]) ? true : false;

    set<int> s;
    s.insert(s.begin(), nums[0]);
    for (int i = 1; i < n; i++)
    {
        if (s.find(nums[i]) == s.end())
        {
            s.insert(s.begin(), nums[i]);
        }
        else
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int a[] = {1, 2, 3};
    int len = sizeof(a) / sizeof(int);
    vector<int>
        v = arr_to_vector(a, len);

    cout << (bool)containsDuplicate(v) << endl;
    /*

    Example 1:
    Input: nums = [1,2,3,1]
    Output: true

    Example 2:
    Input: nums = [1,2,3,4]
    Output: false

    Example 3:
    Input: nums = [1,1,1,3,3,4,3,2,4,2]
    Output: true
    */
}