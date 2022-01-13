/**
 * 题目：
输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否可能为该栈的弹出顺序。
假设压入栈的所有数字均不相等。
例如序列1,2,3,4,5是某栈的压入顺序，序列4,5,3,2,1是该压栈序列对应的一个弹出序列，
但4,3,5,1,2就不可能是该压栈序列的弹出序列。（注意：这两个序列的长度是相等的）
*/

class Solution {
public:
    /**
     * 按照 popV 里的顺序出栈，如果能把 pushV 出栈成空栈，说明 popV 是一种可能的弹出顺序。
    */
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        if (pushV.size() != popV.size())
            return false;
        int length = pushV.size();
        int idPush = 0, idPop = 0;
        stack<int> stk;
        while (idPush < length && idPop < length)
        {
            stk.push(pushV[idPush]);
            while (!stk.empty() && stk.top() == popV[idPop])
            {
                stk.pop();
                idPop++;
            }
            ++idPush;
        }
        // 退出循环有两种情况：
        // 一、idPush 等于 idPop 等于 length，此时 stk 为空，说明 popV 是弹出序列
        // 二、idPush 等于 length，已经压入了最后一个元素，但 stk.top() 还是不等于 popV[idPop]
        if (stk.empty())
            return true;
        else
            return false;
    }
};