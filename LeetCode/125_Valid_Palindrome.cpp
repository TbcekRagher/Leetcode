#include "incl.hpp"
//faster sol
/*
Runtime: 4 ms, faster than 92.20% of C++ online submissions for Valid Palindrome.
Memory Usage: 7.7 MB, less than 29.94% of C++ online submissions for Valid Palindrome.
Next challenges:
 bool isPalindrome(string s) {
        string str;int i;
        for(i=0;i<s.length();i++){
            if(s[i]>=65&&s[i]<=90||s[i]>=97&&s[i]<=122||s[i]>=48&&s[i]<=57)
            str+=tolower(s[i]);
        }
        for(i=0;i<str.length();i++){
            if(str[i]!=str[str.length()-i-1]){
                return 0;
            }
        }
        return 1;
    }
*/

/// cd /mnt/c/Users/YQQ/Desktop/C++函數/LeetCode
/*
Runtime: 8 ms, faster than 53.45% of C++ online submissions for Valid Palindrome.
Memory Usage: 7.7 MB, less than 17.80% of C++ online submissions for Valid Palindrome.


Time S              ubmitted    Status  RuntimeMemory   Language
10/09/2021 19:52	Accepted	8 ms	7.7 MB	cpp
*/
bool isASCIIcharecter(char c)
{
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || s[i] >= 48 && s[i] <= 57)
        return true;
    else
        return false;
}
bool isPalindrome(string s)
{ //A man, a plan, a canal: Panama
    int n = s.length();
    if (n == 0 || n == 1)
        return true;

    vector<char> v;

    for (int i = 0; i < n; i++)
    {
        if (isASCIIcharecter(s[i]))
            v.push_back(tolower(s[i]));
    }
    n = v.size();
    int j = n - 1;
    for (int i = 0; i < n && j > i;)
    {
        //cout << v[i];
        if (v[i] == v[j])
        {

            i++;
            j--;
        }
        else
            return false;
    }
    return true;
}

int main()
{
    /*
    Example 1:
    Input: s = "A man, a plan, a canal: Panama"
    Output: true
    Explanation: "amanaplanacanalpanama" is a palindrome.
    Example 2:

    Input: s = "race a car"
    Output: false
    Explanation: "raceacar" is not a palindrome.
    */
    string s = "A man, a plan, a canal: Panama";
    cout << "\n Ans = " << isPalindrome(s) << endl;
}