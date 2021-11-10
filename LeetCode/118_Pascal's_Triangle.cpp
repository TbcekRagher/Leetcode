#include "incl.hpp"

/// cd /mnt/c/Users/YQQ/Desktop/C++函數/LeetCode
/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Pascal's Triangle.
Memory Usage: 6.4 MB, less than 71.01% of C++ online submissions for Pascal's Triangle.

Time S              ubmitted    Status  RuntimeMemory   Language
10/07/2021 16:35	Accepted	0 ms	6.4 MB	cpp
*/
//https://www.techiedelight.com/initialize-two-dimensional-vector-cpp/
vector<vector<int>> generate(int numRows)
{

    if (numRows == 0)
    {
        vector<vector<int>> v(1, vector<int>(1, 0));
        return v;
    }
    if (numRows == 1)
    {
        vector<vector<int>> v(1, vector<int>(1, 1));
        return v;
    }
    vector<vector<int>> v;
    for (int i = 0; i < numRows; i++)
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
    return v;
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
    vector<vector<int>> v = generate(5);
    vector_print2D(v);
}