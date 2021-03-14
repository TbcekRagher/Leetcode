#include<iostream>
#include<limits>
int reverse(int x) {
        long int rev = 0;
        long int w = x;
        int t;
        if (x<0) w *= -1;
        while(w > 0){
            t = (w%10);
            // if ((long int )rev * 10 > __INT_MAX__)
            rev = rev*10 + t;
            w /= 10;
        }
        if (rev > __INT_MAX__ )return 0;
        if(x<0){rev *= -1;}
        return (int)rev ;   
}
int main()
{
    int x = 1534236469;
    std::cout << reverse(x) << std::endl;
}
