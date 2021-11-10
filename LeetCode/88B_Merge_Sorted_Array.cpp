#include "incl.hpp"
/// cd /mnt/c/Users/YQQ/Desktop/C++函數/LeetCode
/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Merge Sorted Array.
Memory Usage: 9.1 MB, less than 30.59% of C++ online submissions for Merge Sorted Array.
Time S              ubmitted    Status  RuntimeMemory   Language
09/28/2021 16:22	Accepted	0 ms	9.1 MB	        cpp
*/

//I think use int to add and transoform to seperate single unit is faster and easier

//here,I list all case to hit every condition ,but is less efficiency.
void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    if (m == 0 && n != 0)
    {
        nums1.assign(nums2.begin(), nums2.end());
        cout << " nums1.assign(nums2.begin(), nums2.end());" << endl;
        return;
    }
    else if (m == 0 && n == 0)
    {
        return;
    }
    if (n == 0)
        return;
    int i = 0, j = 0, k = 0;
    int a[m + n];
    while (i < m && j < n)
    {
        if (nums1[i] <= nums2[j])
        {
            a[k++] = nums1[i++];
        }
        else
        {
            a[k++] = nums2[j++];
        }
    }
    if (j < n)
    {
        while (j < n)
        {
            a[k++] = nums2[j++];
        }
    }
    else if (i < m)
    {
        while (i < m)
        {
            a[k++] = nums1[i++];
        }
    }
    nums1.assign(a, a + (sizeof(a)) / sizeof(int));
    vector_print_no_newline(nums1);
}

int main()
{
    int a[] = {0};
    int b[] = {1};
    vector<int> v, v2;

    v.assign(a, a + sizeof(a) / sizeof(int));
    v2.assign(b, b + sizeof(b) / sizeof(int));

    //vector_print_no_newline(v);
    //vector_print_no_newline(v2);
    //cout << v.size() << endl;
    merge(v, v.size(), v2, v2.size());
}