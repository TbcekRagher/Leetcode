
#include "incl.hpp"

/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Implement Stack using Queues.
Memory Usage: 6.8 MB, less than 59.46% of C++ online submissions for Implement Stack using Queues.
Time S              ubmitted    Status  RuntimeMemory   Language
10/24/2021 12:46	Accepted	164 ms	76.9 MB	        cpp
*/

class MyStack
{
    vector<int> v;
    int n;

public:
    MyStack()
    {
        n = 0;
    }

    void push(int x)
    {
        v.push_back(x);
        n++;
    }

    int pop()
    {
        int k = v[n - 1];
        v.pop_back();
        n--;
        return k;
    }

    int top()
    {
        return v[n - 1];
    }

    bool empty()
    {
        return (v.size() == 0);
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
class MyStack
{
public:
    queue *q1;
    queue *q2;
    MyStack()
    {
        q1 = new queue();
        q2 = new queue();
    }
    void push(int x)
    {
        q1->push(x);
    }
    int pop()
    {
        int temp;
        while (!q1->empty())
        {
            temp = q1->front();
            q1->pop();
            if (!q1->empty())
            {
                q2->push(temp);
            }
        }
        while (!q2->empty())
        {
            q1->push(q2->front());
            q2->pop();
        }
        return temp;
    }
}

class MyStack {                                 //Runtime: 0 ms, faster than 100.00% of C++ online submissions for Implement Stack using Queues.
public:
    deque<int> dq;                              //A deque with front addition behaves like a stack
    MyStack() {

    }
    void push(int x)
    {
        ios_base::sync_with_stdio(false);
        dq.push_front(x);                       //Elements will be added at the front like a stack
    }

    int pop()
    {
        ios_base::sync_with_stdio(false);
        int x = dq.front();
        dq.pop_front();
        return x;
    }

    int top()
    {
        return dq.front();
    }

    bool empty()
    {
        return (dq.empty());
    }
};