#include "incl.hpp"
/*
Runtime: 4 ms, faster than 58.78% of C++ online submissions for Length of Last Word.
Memory Usage: 6.9 MB, less than 6.09% of C++ online submissions for Length of Last Word.

09/22/2021 11:10	Accepted	4 ms	6.9 MB	cpp
*/

//https://www.delftstack.com/zh-tw/howto/cpp/split-string-in-cpp/

/*fail
58_Length_of_last_Word.cpp:11:21: error: ‘std::__cxx11::string {aka class std::__cxx11::basic_string<char>}’ has no member named ‘find_first_of_not’
     while ((pos = s.find_first_of_not(" ")) != string::npos)

    while ((pos = s.find_first_of_not(" ")) != string::npos)
    {
        s.erase(0, pos);
        pos = find_first_of(" ");
        word = s.substr(0, pos);
        cout << "word : " << word << endl;
        s.erase(0, pos + del.length());
    }
    return word.length();
    */

/* others
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Length of Last Word.
Memory Usage: 6.5 MB, less than 51.72% of C++ online submissions for Length of Last Word.
int lengthOfLastWord(string s) {
      int ans = 0;
    int n = s.size()-1;
    bool f = true;
    for(int i =s.size()-1;i>=0;i--){
        if(s[i] == ' ' and f==true){
            continue;
        }
        else if(s[i] != ' ' and f == true){// and f == true){
            ans++;
            f = false;
        }
        else if(s[i]!=' ' and f == false){
            ans++;
        }
        else if(s[i] == ' ' and f == false){
            break;
        }
    }
     return ans;

    }
*/
int lengthOfLastWord(string s)
{
    if (s.length() == 0)
        return 0;
    int pos = 0;
    string del = " ";
    string word;
    while ((pos = s.find(" ")) != string::npos)
    {
        if (s.substr(0, pos).size() != 0)
            word = s.substr(0, pos);
        cout << "word : " << word << endl;
        s.erase(0, pos + del.length());
    }
    if (s.length() != 0)
        return s.length();
    return word.length();
}

int main()
{
    string s = "luffy is still joyboy";
    cout << lengthOfLastWord(s) << endl;
}