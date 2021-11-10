
#include "incl.hpp"

/*
without inline
Runtime: 8 ms, faster than 61.45% of C++ online submissions for Isomorphic Strings.
Memory Usage: 7 MB, less than 73.93% of C++ online submissions for Isomorphic Strings.
Next challenges:
Time S              ubmitted    Status  RuntimeMemory   Language
10/30/2021 12:16	Accepted	20 ms	15.1 MB	        cpp
*/
/*這題要不適所謂的 1-1 onto 的map 而是 個別分開的map  r map p   p map e  e map  r is ok 所以s and t 都要分開取map 做確認*/
bool isIsomorphic2(string s, string t)
{

    int n = s.length();
    if (n != t.length())
        return false;
    unordered_map<char, char> m;
    m[s[0]] = t[0];
    for (int i = 1; i < n; i++)
    {
        cout << s[i] << " " << t[i] << endl;
        if ((m.count(s[i]) == 0)) //s中第一次出現的配對.
        {
            m[s[i]] = t[i];
        }
        else if (m[s[i]] != t[i])
            return false;
    }

    return true;
}

bool isIsomorphic(string s, string t)
{
    unordered_map<char, char> mp1;
    unordered_map<char, char> mp2;
    int n = s.length();
    for (int i = 0; i < n; i++)
    {
        cout << s[i] << " " << t[i] << endl;
        if (mp1.find(s[i]) == mp1.end())
        {
            mp1[s[i]] = t[i];
            cout << "1 i" << i << endl;
        }
        if (mp2.find(t[i]) == mp2.end())
        {
            mp2[t[i]] = s[i];
            cout << "2 i" << i << endl;
        }
        if (mp1[s[i]] != t[i] || mp2[t[i]] != s[i])
        {
            cout << "3 i" << i << endl;
            return false;
        }
    }
    return true;
}

int main()

{
    /*

    ref https://leetcode.com/problems/isomorphic-strings/discuss/1532904/Simple-C%2B%2B-or-or-Using-Maps
    Example 1:
    Input: s = "egg", t = "add"
    Output: true

    Example 2:
    Input: s = "foo", t = "bar"
    Output: false

    Example 3:
    Input: s = "paper", t = "title"
    Output: true
    */

    string s = "paper";
    string t = "title";

    cout << isIsomorphic(s, t) << endl;
}