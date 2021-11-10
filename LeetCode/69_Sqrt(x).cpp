#include "incl.hpp"
/// cd /mnt/c/Users/YQQ/Desktop/C++函數/LeetCode
int mySqrt(int x)
{
    long high = (x / 2) + 1;
    long low = 0;
    while (high >= low)
    {
        long mid = (high + low) / 2;
        if (mid * mid == x)
            return (int)mid;
        else if (mid * mid > x)
            high = mid - 1;
        else
            low = mid + 1;
        cout << "mid : " << mid << endl;
    }
    return (int)high;
}
/*
int main()
{
    cout << mySqrt(18) << endl;
}
*/