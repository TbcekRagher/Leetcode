//Palindrome Number回文數字reutrn true
#include<iostream>
#include<limits>
#include<cmath>
bool isPalindrome(int x) {
        if (x < 0 || x > __INT_MAX__) return false;
        else{
            long int rev = 0;
            int t ,w = x;
            while(w > 0){
                t = w % 10;
                rev = rev *10 + t;
                w /= 10;
            }
            if (rev == (long int)x )return true;
            else return false;
        }
}
int main()
{
    std::cout <<isPalindrome(121231241255321);
}