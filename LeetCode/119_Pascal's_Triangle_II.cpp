#include "incl.hpp"

/// cd /mnt/c/Users/YQQ/Desktop/C++函數/LeetCode
/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Pascal's Triangle II.
Memory Usage: 6.5 MB, less than 33.42% of C++ online submissions for Pascal's Triangle II.

Time S              ubmitted    Status  RuntimeMemory   Language
10/08/2021 17:55	Accepted	0 ms	6.5 MB	        cpp
*/
//https://www.techiedelight.com/initialize-two-dimensional-vector-cpp/
vector<int> getRow(int rowIndex)
{

    if (rowIndex == 0)
    {
        vector<int> v(1, 1);
        return v;
    }
    if (rowIndex == 1)
    {
        vector<int> v(2, 1);
        return v;
    }
    vector<vector<int>> v;
    for (int i = 0; i <= rowIndex; i++)
    {
        vector<int> tmp(i + 1, 1);
        if (i != 0 || i != 1)
        {
            for (int j = 1; j < i + 1 - 1; j++)
            {
                tmp[j] = v[i - 1][j - 1] + v[i - 1][j];
            }
        }
        v.push_back(tmp);
    }
    return v[rowIndex];
}
template <typename T>
void vector_print2D(vector<vector<T>> &v)
{
    vector<vector<int>>::iterator row;
    vector<int>::iterator col;
    for (row = v.begin(); row != v.end(); row++)
    {
        for (col = row->begin(); col != row->end(); col++)
        {
            cout << *col << " ";
        }
        cout << endl;
    }
}

int main()
{
    vector<int> v = generate(5);
    vector_print_no_newline(v);
}