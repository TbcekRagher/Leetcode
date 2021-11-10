
#include "incl.hpp"

/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Implement Queue using Stacks.
Memory Usage: 6.7 MB, less than 100.00% of C++ online submissions for Implement Queue using Stacks.
Time S              ubmitted    Status  RuntimeMemory   Language
11/05/2021 15:58	Accepted	0 ms	6.7 MB	cpp
*/
/*
class __MyQueue__
{
public:
    vector<int> v;
    MyQueue()
    {
    }

    void push(int x)
    {
        v.push_back(x);
    }

    int pop()
    {
        int a = v[0];
        v.erase(v.begin());
        return a;
    }

    int peek()
    {
        return v[0];
    }

    bool empty()
    {
        return (v.size() == 0);
    }
};
*/
/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

class MyQueue
{
public:
    stack<int> st;
    void push(int x)
    {
        if (!st.size())
        {
            st.push(x);
            return;
        }
        //這段就是透過瘋狂的地回先展開  把所有東西先pop出來再把東西push回去
        int d = st.top();
        cout << "d:" << d << endl;
        cout << "x:" << x << endl;
        cout << "------------------------" << endl;
        st.pop();
        push(x); //這邊是地回呼叫自己。

        st.push(d); //這邊是真的push

        return;
    }

    int pop()
    {
        int tmp = st.top();
        st.pop();
        return tmp;
    }

    int peek()
    {
        return st.top();
    }

    bool empty()
    {
        return !st.size();
    }
};

int main()
{
    MyQueue q;
    q.push(100);

    q.push(200);
    q.push(300);

    q.push(400);
}