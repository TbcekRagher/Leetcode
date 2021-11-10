
#include "incl.hpp"

/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Power of Two.
Memory Usage: 5.9 MB, less than 70.42% of C++ online submissions for Power of Two.
Time S              ubmitted    Status  RuntimeMemory   Language
11/03/2021 15:27	Accepted	0 ms	5.9 MB	cpp
*/

bool isPowerOfTwo(int n)
{
    if (n == 1)
        return true;
    int r = 0;
    int q = 0;
    while (n > 16)
    {
        q = n / 16;
        r = n - q * 16;
        if (r != 0)
            return false;
        n = q;
    }
    if (n == 16 || n == 8 || n == 4 || n == 2 || n == 1)
    {
        return true;
    }
    return false;
}

bool isPowerOfTwo(int n)
{
    if (n <= 0)
        return false;
    while (n != 1)
    {
        if (n & 0x01 > 0x00)
            return false;
        n >>= 1;
    }
    return true;
}
bool isPowerOfTwo(int n)
{
    return (n == 0) ? false : (n == 1)             ? true
                          : (n % 2 == 1 && n != 0) ? false
                                                   : isPowerOfTwo(n / 2);
}