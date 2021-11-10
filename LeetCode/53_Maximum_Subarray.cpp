#include "incl.hpp"
#include <algorithm>
/*
Runtime: 8 ms, faster than 53.50% of C++ online submissions for Maximum Subarray.
Memory Usage: 13.2 MB, less than 55.08% of C++ online submissions for Maximum Subarray.

Status
Runtime
Memory
Language
09/22/2021 00:01	Accepted	8 ms	13.2 MB	cpp
/* ## Java
class Solution {
    public int maxSubArray(int[] nums) {
        int res = nums[0];
        int curr = nums[0];
        for(int i = 1; i < nums.length; i++) {
            curr += nums[i];
            if (curr < 0 || nums[i] > curr)
                curr = nums[i];
            if (res < curr)
                res = curr;
        }
        return res;
    }
}
*/

int maxSubArray(vector<int> &nums)
{
    /*
case1 sum > 0 ,nums[i] > 0  i++; sum = sum+nums[i];
case2 sum > 0 ,nums[i] < 0  比較sum 與maxsum
case1 sum < 0 ,nums[i] > 0  sum = nums[i]
case2 sum < 0 ,nums[i] < 0  sum = 0
*/

    int n = nums.size();
    if (n == 0)
        return 0;
    if (n == 1)
        return nums[0];
    int sum = nums[0], max_sum = nums[0];
    int s = 0, end = 0;

    for (int i = 1; i < n; i++)
    {

        if (sum < 0)
        {
            sum = 0;
            s = i;
        }
        sum = sum + nums[i];
        //
        if (sum > max_sum)
        {
            max_sum = sum;
            end = i;
        }
    }
    cout << "start : " << s << "  end : " << end << endl;
    return max_sum;
}

int maxSubArray1(vector<int> &nums)
{
    int n = nums.size();
    if (n == 0)
        return 0;
    if (n == 1)
        return nums[0];
    int sum = nums[0], max_sum = nums[0];
    int s = 0, end = 0;

    for (int i = 1; i < n; i++)
    {

        sum = sum + nums[i];
        if (sum < 0 || nums[i] > sum)
        {
            sum = nums[i];
            s = i;
        }
        if (sum > max_sum)
        {
            max_sum = sum;
            end = i;
        }
    }
    cout << "start : " << s << "  end : " << end << endl;
    return max_sum;
}
void print_Arr(vector<int> &nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
}

int main()
{
    int a[] = {-2, -1, -3, 4, -1, 2, 1, -5, 4};
    //int a[] = {5, 4, -1, 7, 8};
    vector<int> v;
    v.assign(a, a + sizeof(a) / sizeof(int));
    print_Arr(v);
    cout << "maxSubArray_output :" << maxSubArray1(v) << endl;
}