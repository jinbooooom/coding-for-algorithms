class Solution {
    stack<int> stk;
    stack<int> minstk;
public:
    void push(int value) {
        if (minstk.empty() || value <= minstk.top())    // 注意是 <=
            minstk.push(value);
        stk.push(value);
    }
    void pop() {
        if (minstk.top() == stk.top())
        {
            minstk.pop();
            stk.pop();
        }
        else
            stk.pop();
    }
    int top() {
        return stk.top();
    }
    int min() {
        return minstk.top();
    }
};