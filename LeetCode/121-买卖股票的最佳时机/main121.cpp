class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (!prices.size())
            return 0;
        int min_price = prices[0];
        int dp[prices.size()] = {0};
        for (int i = 1; i < prices.size(); ++i)
        {
            if (prices[i] < min_price)
                min_price = prices[i];
            dp[i] = max(dp[i-1], prices[i] - min_price);
        }
        return dp[prices.size() - 1];
    }


    //方法二，自动状态机：参照 leetcode123(本文件夹下 main123, 或者123-maxProfit3.py)
    int maxProfit2(vector<int>& prices) {
        if(prices.empty())
            return 0;
        //进行初始化，第一天 s1 将股票买入，其他状态全部初始化为最小值
        int s0 = 0;
        int s1 = INT_MIN;  // int s1 = 0x80000000;
        int s2= 0;

        for(int i = 0; i < prices.size(); ++i)
        {
            s1 = max(s1, s0 - prices[i]); //买入价格更低的股
            s2 = max(s2, s1 + prices[i]); //卖出当前股，或者不操作
        }
        return s2 - s0;
    }

};