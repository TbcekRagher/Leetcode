#include "incl.hpp"
/*
Runtime: 4 ms, faster than 80.15% of C++ online submissions for Search Insert Position.
Memory Usage: 9.6 MB, less than 55.97% of C++ online submissions for Search Insert Position.
Next challenges:
First Bad Version
Show off your acceptance:
Time Submitted
Status
Runtime
Memory
Language
09/20/2021 18:30	Accepted	4 ms	9.6 MB	cpp
*/
int searchInsert(vector<int> &nums, int target)
{
    int left = 0;
    int right = nums.size();
    while (left < right)
    {
        int mid = (left + right) / 2;
        if (nums[mid] == target)
            return mid;
        else if (nums[mid] > target)
        {
            right = mid;
        }
        else if (nums[mid] < target)
        {
            left = mid + 1;
        }
    }
    return left;
}
int main()
{
    //#vector
    /*int array[] = {0,1,2,3,4};
    vector v(10,0); // {0,0,0,0,0,0,0,0,0,0}
    vector v1;
    vector v3(v.begin(), v.end())
    v1.assign(10, 0); // v1 設 10 個 0
    v1.assign(v.begin(), v.end()); // v1 複制 v
    v1.assign(v.begin(), v.begin()+5); // 複製 v 前5個元素到 v1
    v1.assign(array, array+5); // 複製 array 前5個元素到 v1

    for (int i = 0; i < 10; i++)
    {
        nums[i] = i;
        cout << nums[i];
    }
    */
    int target = 5;
    vector<int> nums(10);
    int a[] = {1, 3, 5, 6};
    nums.assign(a, a + 4);
    cout << endl;
    cout << searchInsert(nums, target);
}