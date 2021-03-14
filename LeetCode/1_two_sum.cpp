#include<iostream>
#include<vector>
using namespace std;
vector<int> twoSum(vector<int>& nums, int target) {
        int len = nums.size();
        vector<int> index;
        int tmp;
        int a,b;
        for(int i = 0 ; i < len ; i++){
            tmp = nums[i];
            for(int j = i+1 ; j < len ; j++)
            {
                if(((tmp +nums[j])== target)){
                    a = i ; b = j;
                    goto end;
                }
            }
        }
        end:
        if(a > b){
            tmp = a;
            a = b;
            b = tmp;
        }
        index.push_back(a);
        index.push_back(b);
        vector<int>::iterator it;
        for(it = index.begin(); it != index.end() ; ++it){
    }
        return index;
    }
int main()
{
    vector<int> nums ;
    nums.push_back(3);nums.push_back(2);nums.push_back(4);
    vector<int> h;
    vector<int>::iterator it;
    h =  twoSum(nums,6);
    for(it = h.begin(); it != h.end() ; ++it){
        cout << *it << " ";
    }
}