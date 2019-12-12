class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        if (pushV.size() != popV.size())
            return false;
        int length = pushV.size();
        int idPush = 0, idPop = 0;
        stack<int> stk;
        while (idPush < length && idPop < length)
        {
            if (stk.empty())
                stk.push(pushV[idPush++]);
            else if(stk.top() != popV[idPop])
                stk.push(pushV[idPush++]);

            while (!stk.empty() && stk.top() == popV[idPop])
            {
                stk.pop();
                idPop++;
            }
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