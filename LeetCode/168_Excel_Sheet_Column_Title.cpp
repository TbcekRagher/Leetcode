#include "incl.hpp"

/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Excel Sheet Column Title.
Memory Usage: 5.9 MB, less than 76.80% of C++ online submissions for Excel Sheet Column Title.
Time S              ubmitted    Status  RuntimeMemory   Language
10/17/2021 19:57	Accepted	0 ms	5.9 MB	        cpp
*/
string convertToTitle(int columnNumber)
{
    string res = "";
    int v;
    while (columnNumber > 0)
    {
        v = columnNumber % 26; //先用mod找餘數
        if (v == 0)
        {
            v = 26;
        }
        res = (char)(v + 64) + res;
        columnNumber -= v;  //將餘數扣掉後即可整除。
        columnNumber /= 26; //得到下一輪的除數
    }
    return res;
}
inline char int_to_char(int n)
{
    if (n == 0)
        return 'Z';
    return ('A' + n - 1);
}
string convertToTitle(int columnNumber)
{
    int div = 26;
    // A = 65 --> 用64當基底
    if (columnNumber < 0)
        return nullptr;

    vector<char> v;
    string str;
    int q = -1;
    int rem = 0;
    if (columnNumber <= 26)
    {
        v.push_back(int_to_char(columnNumber));
    }
    else
    {
        while (true)
        {
            q = columnNumber / div;       // 72/26 = 2  ... 20   n ==2
            rem = columnNumber - q * div; // 20 = 72 - 2*26      colnumber = 20
            if (rem == 0)
            { /*The code here given a example
                  702 / 26 = 26...26 but in behave code will be (702/26 = 27...0)
                  The Z = 26 have occupy了 value of all . we should considr Z = 26 .
                  another ex 52 /26 = 2...0  It is AZ 52 = 26+26 is a indeed good example to show the
                  diffcultly of this problem
                  Easily to say that we should let "divide remainder" range to be [1,26] rather than the general math concept [0,25]
              */
                q--;
                rem = div;
            }
            columnNumber = q;
            v.insert(v.begin(), int_to_char(rem));
            if (q <= 26)
            {

                v.insert(v.begin(), int_to_char(columnNumber));

                break;
            }
        }
    }
    str.assign(v.begin(), v.end());
    return str;
}
int main()
{
    /*
    iven an integer columnNumber, return its corresponding column title as it appears in an Excel sheet.

    For example:

    A -> 1  B -> 2  C -> 3  ...Z -> 26  AA -> 27    AB -> 28
    int a[] = {-2, -1, -3, 4, -1, 2, 1, -5, 4};
    // int a[] = {5, 4, -1, 7, 8};
    vector<int> v;
    v.assign(a, a + sizeof(a) / sizeof(int));
    v.insert(v.begin(), 100);
    vector_print(v);

    Example 1:
    Input: columnNumber = 1
    Output: "A"

    Example 2:
    Input: columnNumber = 28
    Output: "AB"

    Example 3:
    Input: columnNumber = 701
    Output: "ZY"

    Example 4:
    Input: columnNumber = 2147483647
    Output: "FXSHRXW"

    */

    cout << convertToTitle(702) << endl;
}