/*if(n == 0 || n == 1) it help to fileter the undifed or so-called error string.
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Valid Parentheses.
Memory Usage: 6.2 MB, less than 90.54% of C++ online submissions for Valid Parentheses.
*/
#include<iostream>
#include<string>
#include<cstring>
#include<map>
using namespace std;
 bool isValid(string s) {
    int n = s.size();
    if(n == 0 || n == 1);
    int i = 0;
    char stack[n];
    int top = -1;
    char ptr[n];
    strncpy(ptr,s.c_str(),n);
    std::map <char,char> map  ;
        map.insert(pair<char,char>(')','('));
        map.insert(pair<char,char>(']','['));
        map.insert(pair<char,char>('}','{'));

    while (i < n){
        if(ptr[i] == ')' || ptr[i] == '}' || ptr[i] == ']'){
            if(top == -1 || map[ptr[i]] != stack[top--])return false;
        }else {
            stack[++top] = ptr[i];
        }
        cout << "ptr[" << i << "] =  " << ptr[i] << endl; 
        i++;
    }
    if(top != -1)return false;
    else return true;
}

int main()
{
    string s = "((";
     
    cout << isValid(s) <<endl;
}

/*[{]()[{]}[][]
        */