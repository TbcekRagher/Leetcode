#include "incl.hpp"

/* cost two 2hours
Runtime: 20 ms, faster than 65.95% of C++ online submissions for Missing Number.
Memory Usage: 18.5 MB, less than 6.64% of C++ online submissions for Missing Number.
Time S              ubmitted    Status  RuntimeMemory   Language
10/26/2021 15:03	Accepted	20 ms	18.5 MB	        cpp
*/
int missingNumber(vector<int> &nums)
{
    int sum = nums.size();
    int sum2 = 0;
    for (int i = 0; i < nums.size(); ++i)
    {
        sum += i;
        sum2 += nums[i];
    }
    return sum - sum2;
}
int missingNumber(vector<int> &nums)
{
    int n = nums.size();
    vector<int> v;
    v.assign(nums.begin(), nums.end());
    sort(v.begin(), v.end());
    int i;
    for (i = 0; i < n; i++)
    {
        if (v[i] != i)
        {
            return i;
        }
    }
    return i;
}
int main()
{
    int a[] = {0, 1, 2, 3, 7, 8, 9, 15};
    vector<int> v = arr_to_vector(a, (sizeof(a) / sizeof(int)));
    cout << "missing number is " << missingNumber(v) << endl;
}