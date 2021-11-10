#include "incl.hpp"

/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Excel Sheet Column Number.
Memory Usage: 6.1 MB, less than 26.20% of C++ online submissions for Excel Sheet Column Number.

Time S              ubmitted    Status  RuntimeMemory   Language
10/19/2021 14:23	Accepted	0 ms	6.1 MB          cpp
*/
int titleToNumber(string columnTitle)
{
    int base = 64;
    int n = columnTitle.length();
    auto ptr = columnTitle.c_str();
    cout << ptr << endl;
    if (n == 1)
    {
        return (int)(columnTitle[0] - base)
    }
    int www = (int)columnTitle[n - 1] - base;
    for (int i = n - 2; i >= 0; i--)
    {
        int c = ptr[i];
        // cout << "c " << c - base << endl;
        www = www + ((c - base) * pow(26, (n - i - 1)));
    }
    return www;
}

int main()
{
    /*
        B -> 2      C -> 3...   Z -> 26     AA -> 27        AB -> 28
    Example 1:
    Input: columnTitle = "A"
    Output: 1

    Example 2:
    Input: columnTitle = "AB"
    Output: 28

    Example 3:
    Input: columnTitle = "ZY"
    Output: 701

    Example 4:
    Input: columnTitle = "FXSHRXW"
    Output: 2147483647
    */
    string str = "ZY";
    cout << " " << titleToNumber(str) << endl;
}