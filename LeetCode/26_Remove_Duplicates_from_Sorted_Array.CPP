/*Runtime: 136 ms, faster than 18.76% of C++ online submissions for Remove Duplicates from Sorted Array.
 *Memory Usage: 13.7 MB, less than 50.46% of C++ online submissions for Remove Duplicates from Sorted Array.
 */
#include<iostream>
#include <iomanip>
#include<string>
#include<cstring>
#include<vector>
#include<cstdlib>
#include<cstdio>
using namespace std;
int removeDuplicates(vector<int>& nums) {
    //if (nums.begin() == nums.end()){cerr << "undefined vaule of parameter input\n";exit(0);}
    int cnt = 0;
    vector<int>::iterator cmp = nums.begin();
    
    if(nums.size() == 0)return 0;

    for(vector<int>::iterator it = nums.begin()+1 ; it != nums.end() ; )
    {   
        if (*it == *cmp){
            nums.erase(it);
            continue;
        }else{
            cnt++;
            cmp = it;
        }
        ++it;
    }
    return cnt + 1; 
    //beacause we totally compare cnt times ,but there are cnt + 1 number
}
/*Runtime: 4 ms, faster than 99.05% of C++ online submissions for Remove Duplicates from Sorted Array.
 *Memory Usage: 13.5 MB, less than 91.42% of C++ online submissions for Remove Duplicates from Sorted Array.
 *根本就不用重組刪除多餘的數字陣列，害我做那麼九
 */

int removeDuplicates(vector<int>& nums) {
    
    int i = 0 ,target = 0,cnt = 0;
    int n = nums.size();

    if(n == 0)return 0;

    for(i = 1 ; i < n ; i++)
    {   
        if(nums[i] != nums[target]){
             nums[++target] = nums[i];
        }
    }
    //if(target == 0) nums.resize(0);
    //nums.resize(target);
    return target + 1 ; 
}
void print(vector<int> nums){
    for(vector<int>::iterator it = nums.begin() ; it != nums.end() ; ++it){
        cout << *it << " " ;
    }
    cout <<endl;
}
int main()
{   int s[] = {0,0,0,1,1,1,2,3,3,3,3,4,4,4,5,5,6,6,6,7};
    //int s[] = {0,1,2,3,4};
   
    int n = sizeof(s)/sizeof(int);
    //cout << "n = " << n <<endl;
    vector<int> nums ;
    for(int i = 0 ; i < n ; i++){nums.insert(nums.begin()+i,s[i]);}
    vector<int>::iterator it  = nums.begin()+2;
    //cout << *(it) <<endl;
    //nums.erase(it);
    //cout << *(it)<<endl;
    cout << removeDuplicates(nums) <<endl;
    print(nums);
}


