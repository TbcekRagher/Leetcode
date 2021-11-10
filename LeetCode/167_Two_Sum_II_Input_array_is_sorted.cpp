#include "incl.hpp"

/*
Runtime: 6 ms, faster than 39.90% of C++ online submissions for Two Sum II - Input array is sorted.
Memory Usage: 9.7 MB, less than 9.11% of C++ online submissions for Two Sum II - Input array is sorted.
Time S              ubmitted    Status  RuntimeMemory   Language
10/16/2021 14:23
*/

vector<int> twoSum(vector<int> &numbers, int target)
{
    int first = 0, last = numbers.size() - 1;
    while (first < last)
    {
        if ((numbers[first] + numbers[last]) > target)
        {
            last--;
        }
        else if ((numbers[first] + numbers[last]) < target)
        {
            first++;
        }
        else
        {
            break;
        }
    }
    return {first + 1, last + 1};
}
int main()
{ // ref  :: https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/discuss/1521782/C%2B%2B-oror-Simple-for-Beginner
    /*
    Example 1:
    Input: numbers = [2,7,11,15], target = 9
    Output: [1,2]
    Explanation: The sum of 2 and 7 is 9. Therefore index1 = 1, index2 = 2.

    Example 2:
    Input: numbers = [2,3,4], target = 6
    Output: [1,3]
    Explanation: The sum of 2 and 4 is 6. Therefore index1 = 1, index2 = 3.

    */
}