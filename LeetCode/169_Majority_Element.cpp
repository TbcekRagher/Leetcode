#include "incl.hpp"

/*
RRuntime: 39 ms, faster than 10.23% of C++ online submissions for Majority Element.
Memory Usage: 19.7 MB, less than 10.03% of C++ online submissions for Majority Element.
Next challenges:
Time S              ubmitted    Status  RuntimeMemory   Language
0/18/2021 16:19	Accepted	39 ms	19.7 MB	cpp
*/

int majorityElement(vector<int> &nums)
{
    int n = nums.size();

    if (n == 1)
        return nums[0];

    map<int, int> m;
    map<int, int>::iterator it;

    for (int i = 0; i < n; i++)
    {
        it = m.find(nums[i]);
        if (it != m.end())
        {
            it->second++;
        }
        else
        {
            m.insert(m.begin(), make_pair(nums[i], 1));
        }
    }
    map<int, int>::iterator max_it = m.begin();
    for (it = m.begin(); it != m.end(); it++)
    {
        if (it->second > max_it->second)
        {
            max_it = it;
        }
    }
    return max_it->first;
}

int majorityElement2(vector<int> &nums)
{
    /*
    Runtime: 16 ms, faster than 85.48% of C++ online submissions for Majority Element.
  Memory Usage: 19.7 MB, less than 10.03% of C++ online submissions for Majority Element.
    */
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int cnt = 0;
    if (n == 1)
        return nums[0];
    for (int i = 0; i < n - 1; i++)
    {
        if (nums[i] == nums[i + 1])
        {
            cnt++;
            if (cnt >= n / 2) //#超過一半基本可以確定是最大
                return nums[i];
        }
        else
            cnt = 1; //數字換了
    }
    return -1;
}
int main()
{
    /*
    Example 1:
    input: nums = [3,2,3]
    Output: 3

    Example 2:
    Input: nums = [2,2,1,1,1,2,2]
    Output: 2
    */
    int a[] = {3, 2, 3};
    vector<int> v;
    v.assign(a, a + (sizeof(a) / sizeof(int)));
    cout << " max  = " << majorityElement(v) << endl;
}