#include "incl.hpp"

/*
without inline
Runtime: 4 ms, faster than 44.20% of C++ online submissions for Happy Number.
Memory Usage: 5.9 MB, less than 86.29% of C++ online submissions for Happy Number.
with inline
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Happy Number.
Memory Usage: 6 MB, less than 67.04% of C++ online submissions for Happy Number.
Time S              ubmitted    Status  RuntimeMemory   Language
10/28/2021 16:39	Accepted	4 ms	5.9 MB	    cpp
*/
inline int __isHappy10(int n)
{ //max int 2^31-1 --> 4* 10^9 <10^10
    //#專門算位數的平方總和
    int sum = 0;
    int k;
    while (n != 0)
        s
        {
            k = n % 10;
            sum += k * k;
            n /= 10;
        }
    cout << "sum = " << sum << endl;
    return sum;
}
bool isHappy(int n)
{
    if (n == 1)
        return true;
    else if (n == 2 || n == 3)
        return false;
    int k = __isHappy10(n);
    while (k > 4) //#說真的不知道這個4是哪來的。我沒看過數學證明，所以我無法信服4 到底怎麼得出來的
    {
        k = __isHappy10(k);
    }
    if (k == 1)
        return true;
    else
        return false;
}
bool isHappy(int n)
{ /*
    Runtime: 0 ms, faster than 100.00% of C++ online submissions for Happy Number.
Memory Usage: 5.9 MB, less than 67.04% of C++ online submissions for Happy Number.
*/
    vector<int> arr;
    int res = n;
    while (true)
    {
        while (res != 0)
        {
            int k = res % 10;
            arr.push_back(k);
            res = res / 10;
        }
        for (int i = 0; i < arr.size(); i++)
        {
            res += pow(arr[i], 2);
        }
        arr.clear();
        if (res == 1)
            return true;
        else if (res < 5)
            return false;
    }
    return false;
}
int main()
{
    cout << isHappy(7) << endl;
}