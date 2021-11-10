/*Runtime: 0 ms, faster than 100.00% of C++ online submissions for Implement strStr().
 *Memory Usage: 7 MB, less than 42.20% of C++ online submissions for Implement strStr().
 *Use the K.M.P alogrithm find the largest supstring ,and return to caller when the sub string is found. 
 */ 
#include<iostream>
#include <iomanip>
#include<string>
#include<cstring>
#include<vector>
#include<cstdlib>
#include<cstdio>
using namespace std;
int strStr(string haystack, string needle) {
    if (haystack.size() == 0 && needle.size() == 0) return 0;   //src empty
    else if (haystack.size() == 0) return -1;
    else if(needle.size() == 0) return 0;  //target is empty;
    int n = haystack.size(),m = needle.size();
    char str[n],qtr[m]; 
    int f[m];   f[0] = -1;
    int i ,j = 0;
    strncpy(str,haystack.c_str(),n);strncpy(qtr,needle.c_str(),m);
    //failure function min value is -1;
    for ( i = 1 ; i < m ; i++ )
    {   
        j = f[i-1];
        while(qtr[i] != qtr[j+1]&& (j >= 0)){j =  f[j];}
        if (qtr[i] == qtr[j+1])f[i] = j+1;
        else f[i] = -1; 
    }
    //for K.M.P-compare's min value is 0;
    for ( i = 0 ; i < m ; i++ ){f[i]++;}//cout << f[i] ;

    i = 0, j = 0;
    while (i < n){
        if (str[i] == qtr[j]){i++;j++;}
        if ( j == m){return i-j;}//cout <<"i -j = " << i-j << endl;j =  f[j-1];
        else if((i < n)  && str[i] != qtr[j])
        {
            if (j != 0)j = f[j-1];
            else i++;
        }
    }
    return -1;
}
int main()
{      

    string s = "ababcaababcaabc";
    cout << "hew =  ::" << strStr(s,"ababcaabc") << endl ;
}