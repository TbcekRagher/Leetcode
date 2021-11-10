/*Solution of Longest_Substring_Without_Repeating_Characters
 *It is modified from someone else's code .
 *This excercise has fail ,so the filename will add the "fail" at the beginning of the file name
 */
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<set>
#include<map>
/*Brute Force*/
using namespace std;
    bool allUnique(char *s, int start, int end) {
        set<char> set;
        for (int i = start; i < end; i++) {
            char ch = s[i];
            if (set.count(ch)) return false;    //在set裡面有s[i]就表示重複了
            set.insert(ch);
        }
        return true;
    }

    int lengthOfLongestSubstring_Brute_Force(string s) {
        int n = s.length();
        int ans = 0;
        char ptr[s.length()];
        strncpy(ptr,s.c_str(), s.length());
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j <= n; j++)
                if (allUnique(ptr, i, j)) ans = max(ans, j - i);
        return ans;
    }

/*sliding windowsmethod */
inline int max (const int & a, const int & b ){
    if (a > b)return a;
    else return b;
}
 int lengthOfLongestSubstring_slide_window(string s) {
        int n = s.length(); 
        char ptr[n];
        strncpy(ptr,s.c_str(),n);
        set<char> set ;
        int ans = 0, i = 0, j = 0;
        while (i < n && j < n) {
            // try to extend the range [i, j]
            if (!set.count(ptr[j])){
                set.insert(ptr[j++]);
                ans = max(ans, j - i);
            }
            else {
                set.erase(ptr[i++]);
            }
        }
        return ans;
    }

/*Sliding Window Optimized :we don't need using a set to tell if a character exists or not
 *by using "map"
 *
 */
int lengthOfLongestSubstring_slide_window_opt(string s) {
        int n = s.length(), ans = 0;
        map<char, int> map ; // current index of character
        char ptr[n];
        strncpy(ptr,s.c_str(),n);
        // try to extend the range [i, j]
        for (int j = 0, i = 0; j < n; j++) {
            if (map.count(ptr[j])) {//at(key) input key and get the corresponding value at map[j];
                i = max(j, i);  //if ptr[j] has been in map ,we reset the new start of substring.
            }
            ans = max(ans, j - i + 1);  //at least one
            map.insert(pair<char, int>(ptr[j], j + 1));
        }
        return ans;
    }

int main()
{   int x ;
    string s = "abcdswzwfswq";
    //cout << lengthOfLongestSubstring_Brute_Force(s) << endl;
    //cout << lengthOfLongestSubstring_slide_window(s) << endl;
    cout << lengthOfLongestSubstring_slide_window_opt(s) << endl;
    
}