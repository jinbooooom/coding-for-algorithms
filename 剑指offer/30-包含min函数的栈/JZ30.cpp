/**
 * 题目：
 * 定义栈的数据结构，请在该类型中实现一个能够得到栈中所含最小元素的 min 函数 (时间复杂度应为 O(1))。
*/

class Solution
{
    stack<int> stk;
    stack<int> minstk;

public:
    void push(int value)
    {
        if (minstk.empty() || value <= minstk.top()) // 注意是 <=
            minstk.push(value);
        stk.push(value);
    }
    void pop()
    {
        if (minstk.top() == stk.top())
        {
            minstk.pop();
            stk.pop();
        }
        else
            stk.pop();
    }
    int top()
    {
        return stk.top();
    }
    int min()
    {
        return minstk.top();
    }
};