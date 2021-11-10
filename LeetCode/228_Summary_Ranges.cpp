#include "incl.hpp"

/* cost two 2hours
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Summary Ranges.
Memory Usage: 6.9 MB, less than 13.14% of C++ online submissions for Summary Ranges.
Time S              ubmitted    Status  RuntimeMemory   Language
10/25/2021 17:56	Accepted	0 ms	6.9 MB	cpp
*/
vector<string> summaryRanges(vector<int> &a)
{ //[0,1,2,3,8,9,13,14,15]
    //[0,1,2,3,8,9,15]
    //-1, 8, 9, 10, 13, 14, 15
    int n = a.size();
    vector<string> v;
    if (n == 0)
        return v;
    else if (n == 1)
    {
        v.push_back(to_string(a[0]));
        return v;
    }
    int i = 1, j = a[0], cnt = a[0];
    //          j       cnt   0 ,  1,  2,  3,  7,  8,  9,  15 n = 8
    // run1     0       0        a[i]
    // run2     0       1             a[i]
    // run3     0       2     ----------- a[i]
    // run4     7       3->7  --------------- a[i]
    // run5     7       8     --------------------a[i]
    // run6     7       9     ---------------------- a[i]
    // run7     15      9->15 --------------------------  a[i]
    for (; i < n;)
    {
        cout << " i = " << i;
        cout << " j = " << j;
        cout << " a = " << a[i];
        cout << " cnt = " << cnt << endl;
        if (a[i] == (cnt + 1)) //if a[i]-a[i-1] = 1 will come to here.
        {
            cnt++;
            if (i == n - 1)
            {
                v.push_back(to_string(j) + "->" + to_string(cnt));
            }
        }
        else
        {
            if (cnt - j == 0) //if come to here means the number (a[i] -a[i-1]) >2 && abs(a[i]-a[i+1])>2 --> a[i] is single,note:here a[i] equal the cnt
            {
                v.push_back(to_string(cnt));
            }
            else //if come to here means a[i]-a[i-1] >2 is not continous. so we store a[j] to a[i-1]
            {
                v.push_back(to_string(j) + "->" + to_string(cnt));
            }
            cnt = j = a[i]; //because a[i]-a[i-1] != 1 so that we reset the left of new interval [j~?]
            if (i == n - 1)
            {
                v.push_back(to_string(cnt));
            }
        }
        i++;
    }
    return v;
}
vector<string> summaryRanges(vector<int> &nums)
{
    vector<string> res;
    int n = nums.size(), idx = 0;
    if (n == 0)
        return res;
    for (int i = 1; i < n; i++)
    {
        if (nums[i] == nums[i - 1] + 1)
            continue;
        res.push_back(to_string(nums[idx]) + (i == idx + 1 ? "" : "->" + to_string(nums[i - 1]))); //如果沒有經過continue 那麼i -idx 一定是1 。
        idx = i;
    }
    res.push_back(to_string(nums[idx]) + (idx == n - 1 ? "" : "->" + to_string(nums[n - 1])));
    return res;
}
int main()
{
    int a[] = {0, 1, 2, 3, 7, 8, 9, 15};
    vector<int> v = arr_to_vector(a, (sizeof(a) / sizeof(int)));
    vector<string> s = summaryRanges(v);
    vector_print_no_newline(s);
}

/* fail
vector<string> summaryRanges2(vector<int> &a)
{ //[0,1,2,3,8,9,13,14,15]
    int n = a.size();

    vector<string> v;
    if (n == 0)
        return v;
    else if (n == 1)
    {
        v.push_back(to_string(a[0]));
        return v;
    }
    int i = 0, j = a[0];
    int cnt = a[0];

    for (; i < n;)
    { //v.append(to_string(j) + "->" + to_string(i));
        if (a[i] == cnt && i != n - 1)
        {
            i++;
        }
        else if (a[i] != cnt)
        {
            if (j < a[i - 1])
            {
                v.push_back(to_string(j) + "->" + to_string(a[i - 1]));
                j = a[i];
            }
        }
        else
        {
            cout << "for end()" << endl;
            break;
        }
        cout << " i = " << i;
        cout << " j = " << j;
        cout << " a = " << a[i];
        cout << " cnt = " << cnt << endl;
    }
    if (cnt != a[i])
    {
        v.push_back(to_string(a[i]));
    }
    else
    {
        v.push_back(to_string(j) + "->" + to_string(a[i]));
    }
}

vector<string> summaryRanges(vector<int> &a)
{ //[0,1,2,3,8,9,13,14,15]
    //[0,1,2,3,8,9,15]
    int n = a.size();
    vector<string> v;
    if (n == 0)
        return v;
    else if (n == 1)
    {
        v.push_back(to_string(a[0]));
        return v;
    }
    int i = 0,j = a[0],cnt = a[0];
    int ;
    for (i = 0; i < n;)
    {
        if (i == n - 1)
        {
            if (cnt == a[i]) //到最後還是連續的
            {
                v.push_back(to_string(j) + "->" + to_string(a[i]));
            }
            else
            { //因為把push_back放到了a[i+1]回合去做，所以如果再k~n-2都是連續 ,但n-1時才做，所以這邊要補一下這個push
                v.push_back(to_string(j) + "->" + to_string(a[i - 1]));
                v.push_back(to_string(a[i]));
            }
            break;
        }
        if (a[i] == cnt)
        {

            cnt = a[i] + 1;
            i++;
        }
        else
        {
            v.push_back(to_string(j) + "->" + to_string(a[i - 1]));
            cnt = j = a[i];
        }
    }

    return v;
}
*/