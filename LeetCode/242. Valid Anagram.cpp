

#include "incl.hpp"

/*這個算是一次救過，然後完全沒有test  我超猛的拉
Runtime: 12 ms, faster than 54.07% of C++ online submissions for Valid Anagram.
Memory Usage: 7.7 MB, less than 7.11% of C++ online submissions for Valid Anagram.
Time S              ubmitted    Status  RuntimeMemory   Language
11/10/2021 16:53	Accepted	12 ms	7.7 MB	cpp
*/
/*
Input: s = "anagram", t = "nagaram"
Output: true
*/

unordered_map<char, int> count(string s)
{
    unordered_map<char, int> m;
    for (int i = 0; i < s.length(); i++)
    {
        if (m.find(s[i]) != m.end())
        {
            m[s[i]]++;
        }
        else
        {
            m[s[i]] = 0;
        }
    }
    return m;
}
bool isAnagram(string s, string t)
{
    if (s.length() != t.length())
        return false;
    unordered_map<char, int> m = count(s);
    unordered_map<char, int> n = count(t);
    for (auto &item : m)
    {
        if (n.find(item.first) != n.end())
        {
            if (item.second != (n.find(item.first)->second))
            {
                return false;
            }
        }
        else
            return false;
    }
    return true;
}

bool isAnagram(string s, string t)
{ /*
    Runtime: 8 ms, faster than 82.41% of C++ online submissions for Valid Anagram.
Memory Usage: 7.3 MB, less than 44.41% of C++ online submissions for Valid Anagram.
    */
    // Checking if length of both the strings are equal or not.
    if (s.length() != t.length())
        return false;
    // We have to declare map for counting frequency of the character
    unordered_map<char, int> ma;
    // Now for every character in  s string we are increasing value by one
    // For every character in t string we are decreasing value by one
    // For eg :- if s=aabc, and t=abca , for s string (a=2,b=1,c=1) for t string (a=0=,b=0,c=0)

    for (int i = 0; i < s.size(); i++)
    // Iterate throught the string
    {
        // Increase the number of frequency
        ma[s[i]]++;
        // Decrease the number of frequency
        ma[t[i]]--;
    }
    //Iterate throught the map
    for (auto i : ma)
    {
        // If the frequency (value) becomes 0 for every character that means two strings are anagram
        // If frequency (value) becomes less that 0 that means we are left with some character in our map so given  two strings are not anagram
        if (i.second < 0)
        {
            return false;
        }
    }
    return true;
}
int main()
{
}