#include "incl.hpp"
/// cd /mnt/c/Users/YQQ/Desktop/C++函數/LeetCode
//把所有條件都判斷的寫法超級難debug
/*
Runtime: 4 ms, faster than 61.71% of C++ online submissions for Add Binary.
Memory Usage: 6.6 MB, less than 40.23% of C++ online submissions for Add Binary.
Time S              ubmitted      Status      RuntimeMemory   Language
09/24/2021 23:38	Accepted	    4 ms	    6.6 MB	        cpp
*/

string addBinary(string a, string b)
{
    int i = a.length(), j = b.length();

    if (i == 0)
        return b;
    else if (j == 0)
        return a;
    else if (i == 0 && j == 0)
        return "0";
    bool carry = false;

    i -= 1;
    j -= 1;
    vector<char> v;
    //
    //cout << "ans : " << ans << endl;
    while (i >= 0 && j >= 0)
    {
        if (a[i] == '0' && b[j] == '0')
        {
            if (carry == false) //大家都0所以一定0
            {
                v.insert(v.begin(), '0');
            }
            else
            { //前一位有進位，但這位都0所以只加入carry
                carry = false;
                v.insert(v.begin(), '1');
            }
        }
        else if ((a[i] == '1' && b[j] == '0') || a[i] == '0' && b[j] == '1')
        {
            if (carry == false)
            {
                v.insert(v.begin(), '1');
            }
            else
            { //這邊已經是true了 而且這回合也會觸發進位保險一點這邊還是要設定，因為一開始carry是false
                carry = true;
                v.insert(v.begin(), '0');
            }
        }
        else if (a[i] == '1' && b[j] == '1' && carry == false)
        {
            carry = true;
            v.insert(v.begin(), '0');
        }
        else if (a[i] == '1' && b[j] == '1' && carry == true)
        {
            carry = true;
            v.insert(v.begin(), '1');
        }
        i--;
        j--;
    }
    vector_print(v);
    cout << "----------------------" << endl;
    //#善後部隊 110001
    if (i >= 0)
    {

        while (i >= 0)
        {
            vector_print_no_newline(v, false);
            if (a[i] == '0')
            {
                if (carry == false)
                {
                    v.insert(v.begin(), '0');
                }
                else
                {
                    carry = false;
                    v.insert(v.begin(), '1');
                }
            }
            else //(a[i] == '1')
            {
                //cout << "i = " << i << "carry = " << carry << endl;
                if (carry == false)
                {
                    v.insert(v.begin(), '1');
                }
                else
                {
                    //carry = true;
                    v.insert(v.begin(), '0');
                }
            }
            i--;
        }
    }
    else if (j >= 0)
    {
        i = j;
        while (i >= 0)
        {
            if (b[i] == '0')
            {
                if (carry == false)
                {
                    v.insert(v.begin(), '0');
                }
                else
                {
                    carry = false;
                    v.insert(v.begin(), '1');
                }
            }
            else //(a[i] == '1')
            {
                if (carry == false)
                {

                    v.insert(v.begin(), '1');
                }
                else
                {
                    carry = true;
                    v.insert(v.begin(), '0');
                }
            }
            i--;
        }
    }

    if (carry == true)
        v.insert(v.begin(), '1');
    cout << "end concurrently" << endl;
    cout << "end  " << endl;
    string ans;
    ans.insert(ans.begin(), v.begin(), v.end());
    return ans;
}

int main()
{
    string a = "11";
    string b = "1";

    //#test vector push back
    /*vector<char> v;
    v.push_back('1');
    vector_print(v);
    */
    cout << "a : " << a << endl;
    cout << "b : " << b << endl;
    string ans = addBinary(a, b);
    cout << "ans :" << ans << endl;
}