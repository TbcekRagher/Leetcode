/*Runtime: 0 ms, faster than 100.00% of C++ online submissions for Remove Element.
 *Memory Usage: 8.8 MB, less than 51.37% of C++ online submissions for Remove Element.
 */
#include<iostream>
#include <iomanip>
#include<string>
#include<cstring>
#include<vector>
#include<cstdlib>
#include<cstdio>
using namespace std;
int removeElement2(vector<int>& nums, int val) { //iterator method
    int n = nums.size();
    if (n == 0)return 0;
    for (vector<int>::iterator it = nums.begin() ; it != nums.end() ;){
        if (*it == val){
            n--;
            nums.erase(it);
        }else{  ++it;   }
    }
    return n;
}

int removeElement(vector<int>& nums, int val) { //i method
    int n = nums.size();
    int j = 0;
    if (n == 0)return 0;
    for (int i = 0 ;  i < n ; i++){
        if (nums[i] != val){
           nums[j] = nums[i];
            j++;
        }
    }
    //nums.resize(j);
    return j;
    /*Runtime: 4 ms, faster than 52.40% of C++ online submissions for Remove Element.
     *Memory Usage: 8.7 MB, less than 92.80% of C++ online submissions for Remove Element.
     *  without resize;
     */
}
void print(vector<int> nums){
    for(vector<int>::iterator it = nums.begin() ; it != nums.end() ; ++it){
        cout << *it << " " ;
    }
    cout <<endl;
}
int main()
{
    int s[] = {0,1,2,2,3,0,4,2};
    int n = sizeof(s)/sizeof(int);
    vector<int>  nums;
    for (int i = 0 ; i < n ; i++)
    {
        nums.insert(nums.begin()+i,s[i] );
    }
    cout << "@Q@@ = " << removeElement(nums,2) << endl;
    print(nums);
}