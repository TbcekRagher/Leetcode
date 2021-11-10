#include "incl.hpp"

/*


Time S              ubmitted    Status  RuntimeMemory   Language

*/

uint32_t reverseBits(uint32_t n)
{
    unsigned int ans = 0;

    for (unsigned int i = 0; i < 32; i++)
    {
        ans += ((n & 1 << i) ? 1 : 0) << (31 - i);
    }

    return ans;
}
int main()
{   uint32_t n = 1101;
    cout << reverseBits((n)) << endl;
    /*ref :https://leetcode.com/problems/reverse-bits/discuss/1530031/C%2B%2B-solution

    */
}