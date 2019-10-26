class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty())
            return 0;
        //进行初始化，第一天 s1 将股票买入，其他状态全部初始化为最小值
        int s0 = 0;
        int s1 = INT_MIN;
        int s2= 0;
        int s3 = INT_MIN;
        int s4 = 0;

        for(int i = 0; i < prices.size(); ++i)
        {
            s1 = max(s1, s0 - prices[i]); //买入价格更低的股
            s2 = max(s2, s1 + prices[i]); //卖出当前股，或者不操作
            s3 = max(s3, s2 - prices[i]); //第二次买入，或者不操作
            s4 = max(s4, s3 + prices[i]); //第二次卖出，或者不操作
        }
        return s4 - s0;
    }
};
