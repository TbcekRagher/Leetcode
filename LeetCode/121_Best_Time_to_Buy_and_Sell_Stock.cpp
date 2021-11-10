#include "incl.hpp"

/// cd /mnt/c/Users/YQQ/Desktop/C++函數/LeetCode
/*
Runtime: 104 ms, faster than 93.95% of C++ online submissions for Best Time to Buy and Sell Stock.
Memory Usage: 93.3 MB, less than 91.35% of C++ online submissions for Best Time to Buy and Sell Stock.
Next challenges:

Time S              ubmitted    Status  RuntimeMemory   Language
10/08/2021 18:35	Accepted	104 ms	93.3 MB	        cpp
*/
int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    if (n == 0 || n == 1)
        return 0;
    if (n == 2)
        return (prices[0] > prices[1]) ? (0) : (prices[1] - prices[0]);
    int cur = 0;     //cur_BestPrice_idx紀錄現在賣的最高價格
    int low_idx = 0; // lowest_pay_idx 紀錄買進的最低價格
    int max_p = 0;
    for (int i = 1; i < n; i++)
    {                                    //[7,1,5,3,6,4]
        if (prices[i] > prices[low_idx]) //prices[i] - prices[low_idx]>0
        {
            if (i > low_idx)
            {
                max_p = max(max_p, prices[i] - prices[low_idx]);
                if (prices[i] < prices[i + 1])
                {

                    continue;
                }
            }
            else //error detect
            {
                cout << "invaild operation  "
                     << "Line : " << __LINE__ << " function : " << __func__ << endl;
                exit(0);
            }
        }
        else if (prices[i] <= prices[low_idx])
        {
            if (i > low_idx)
            {
                low_idx = i;
            }
            else //error detect
            {
                cout << "invaild operation  "
                     << "Line : " << __LINE__ << " function : " << __func__ << endl;
                exit(1);
            }
        }
    }
    return max_p;
}
int main()
{
    /*[1,6,3,2,22,6]
    Input: prices = [7,1,5,3,6,4]
    Output: 5
    Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
    Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
    Example 2:

    Input: prices = [7,6,4,3,1]
    Output: 0
    Explanation: In this case, no transactions are done and the max profit = 0.
    */
    int a[] = {1, 6, 3, 2, 22, 6};
    vector<int> v;
    v.assign(a, a + (sizeof(a) / sizeof(int)));
    cout << "maxProfit  :" << maxProfit(v) << endl;
}