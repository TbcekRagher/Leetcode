#include "incl.hpp"

/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Number of 1 Bits.
Memory Usage: 6 MB, less than 48.33% of C++ online submissions for Number of 1 Bits.

Time S              ubmitted    Status  RuntimeMemory   Language
10/21/2021 16:42	Accepted	0 ms	6 MB	        cpp
*/

int hammingWeight(uint32_t n)
{
    int cnt = 0;

    for (unsigned int i = 0; i < 32; i++)
    {
        //ans += ((n & 1 << i) ? 1 : 0) << (31 - i);
        cnt += ((n & 1 << i) ? 1 : 0)
        //第一回合先讓 第 0 -th bit(LSB) 去跟 1的第一位比，//第二回合讓第1-th bit 去跟 1 <<2 = 10比
        //      101
        //and    10
        //       00
    }

    return cnt;
}
int main()
{
    uint32_t n = 1101;

    /*ref :

    */
}