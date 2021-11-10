#include "incl.hpp"

/*
Runtime: 34 ms, faster than 27.53% of C++ online submissions for Min Stack.
Memory Usage: 16.3 MB, less than 68.88% of C++ online submissions for Min Stack.
Next challenges:
Time S              ubmitted    Status  RuntimeMemory   Language
10/14/2021 20:13	Accepted	34 ms	16.3 MB	        cpp
*/
/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

class MinStack
{
    vector<pair<int, int>> v;

public:
    MinStack()
    {
    }

    void push(int val)
    {
        if (v.size() == 0)
        {
            v.push_back(make_pair(val, val));
        }
        else
        {
            v.push_back(make_pair(val, min(val, v.getMin())))
        }
    }

    void pop()
    {
        v.pop_back();
    }

    int top()
    {
        return v[v.size() - 1].first;
    }

    int getMin()
    {
        return v[v.size() - 1].second;
    }
};

int main()
{
    MinStack minStack = new MinStack();
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    minStack.getMin(); // return -3
    minStack.pop();
    minStack.top();    // return 0
    minStack.getMin(); // return -2
}