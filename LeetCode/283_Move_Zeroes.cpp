#include "incl.hpp"

/*
Runtime: 112 ms, faster than 6.82% of C++ online submissions for Move Zeroes.
Memory Usage: 19.3 MB, less than 32.29% of C++ online submissions for Move Zeroes.
Time S              ubmitted    Status  RuntimeMemory   Language
10/27/2021 17:25	Accepted	112 ms	19.3 MB	        cpp
*/

void moveZeroes1(vector<int> &v)
{
    int n = v.size();
    int i = 0;
    if (n == 0 || n == 1)
        return;
    vector<int>::iterator it = v.begin();
    for (i = 0; i < n; i++)
    {
        if (*it == 0)
        {
            v.erase(it);
            v.push_back(0);
        }
        else
        {
            it++;
        }
    }
}
void moveZeroes(vector<int> &v)
{ /*
    Runtime: 20 ms, faster than 50.86% of C++ online submissions for Move Zeroes.
    Memory Usage: 19.3 MB, less than 7.38% of C++ online submissions for Move Zeroes.
    */
    int n = v.size();
    int i = 0, cnt_0 = 0;

    if (n == 0 || n == 1)
        return;
    for (; i < n; i++)
    {
        if (v[i] != 0)
            v[cnt_0++] = v[i];
    }
    for (i = cnt_0; i < n; i++)
    {
        v[i] = 0;
    }
}
void moveZeroes3(vector<int> &nums)
{
    vector<int>::iterator it = remove(nums.begin(), nums.end(), 0);
    for (; it != nums.end(); it++)
    {
        *it = 0;
    }
}

void moveZeroes(vector<int> &nums)
{
    int j = 0;
    for (int i = 0; i < nums.size(); i++)
        if (nums[i] != 0)
            nums[j++] = nums[i];

    for (int i = j; i < nums.size(); i++)
        nums[i] = 0;
}
int main()
{
    /*
    Input: nums = [0,1,0,3,12]
    Output: [0,1,0,3,12]
    */
    int a[] = {0, 1, 0, 0, 0, 3, 12};
    vector<int> v = arr_to_vector(a, (sizeof(a) / sizeof(int)));
    moveZeroes3(v);
    vector_print_no_newline(v);
}