#include "incl.hpp"
//faster sol
/*
Runtime: 56 ms, faster than 5.47% of C++ online submissions for Single Number.
Memory Usage: 16.8 MB, less than 99.18% of C++ online submissions for Single Number.


Time S              ubmitted    Status  RuntimeMemory   Language
10/11/2021 16:50	Accepted	56 ms	16.8 MB	        cpp
Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

You must implement a solution with a linear runtime complexity and use only constant extra space.
*/

/*此題的秘訣在於 兩個同樣的數字 a xor a = 0  落單的數字跟 b xor 0 會等於 b  但這個地方有個問題就是只要是奇數救會出問題*/
int singleNumber(vector<int> &nums)
{
    int x = 0;
    for (auto &i : nums)
    {

        x ^= i;
        cout << "x = " << x << endl;
    }

    return x;
}
int main()
{
    /*
    Example 1:
    Input: nums = [2,2,1]
    Output: 1

    Example 2:
    Input: nums = [4,1,2,1,2]
    Output: 4

    Example 3:
    Input: nums = [1]
    Output: 1
    */
    int a[] = {4, 1, 2, 1, 2, 2};
    vector<int> v;
    int c = 1;
    c ^= 3;
    cout << "w :" << c << endl;
    v.assign(a, a + (sizeof(a) / sizeof(int)));
    cout << "singleNumbe:" << singleNumber(v) << endl;

    /* reference    :https://medium.com/@hyWang/xor-%E4%BD%8D%E5%85%83%E9%81%8B%E7%AE%97%E5%AD%90-1c25b4ae15fb*/
}