#include "incl.hpp"
/// cd /mnt/c/Users/YQQ/Desktop/C++函數/LeetCode
/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Climbing Stairs.
Memory Usage: 6.2 MB, less than 14.31% of C++ online submissions for Climbing Stairs.
Time S              ubmitted    Status  RuntimeMemory   Language
09/27/2021 17:44	Accepted	0 ms	6.2 MB	        cpp
*/

/*
#Note : 第一層的方法只有一種 1= 1
        第二層的方法有2種   2 = 1+1
        第三層的方法有3種   3 = 1+1+1 = 2+1 +1+2
        第四層的方法有5種   4 = 1+1+1+1  = 1+1+2 = 1+2+1 =2+1+1 = 1+3
        正好對應了 fabnoacci
        0    1   2   3   4   5  6   7
        1    1   2   3   5   8  13  21
*/
int climbStairs(int n)
{
    int *a = new int[n + 1];
    a[0] = 1;
    a[1] = 1;
    for (int i = 2; i <= n; ++i)
    {
        a[i] = a[i - 1] + a[i - 2];
    }
    return a[n];
}