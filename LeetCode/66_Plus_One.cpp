#include "incl.hpp"
#include <algorithm>
/// cd /mnt/c/Users/YQQ/Desktop/C++函數/LeetCode

/**
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Plus One.
Memory Usage: 8.8 MB, less than 12.88% of C++ online submissions for Plus One.
Time S              ubmitted      Status      RuntimeMemory   Language
09/23/2021 18:34	Accepted	    0 ms	    8.8 MB	        cpp
*/
vector<int> plusOne(vector<int> &digits)
{
    int n = digits.size();
    int sum = 0;
    if (n == 0)
    {
        digits.push_back(1);
    }
    else if (n == 1 && digits[0] < 9)
    {
        digits[0] += 1;
    }
    else if (digits[n - 1] < 9)
    {
        digits[n - 1] += 1;
    }
    else if (digits[n - 1] == 9)
    {
        int i = n - 1;
        digits[i] += 1;

        for (; i > 0; i--)
        {
            if (digits[i] == 10)
            {
                digits[i] = 0;
                digits[i - 1] += 1;
            }
        }
        if (digits[i] == 10)
        {
            digits[i] = 0;
            digits.insert(digits.begin(), 1);
        }
    }
    return digits;
}

int main()
{
    //int a[] = {1, 2, 3}; ok
    //int a[] = {0}; ok
    int a[] = {8, 9};
    vector<int> v;
    v.assign(a, a + (sizeof(a) / sizeof(int)));
    v = plusOne(v);

    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}