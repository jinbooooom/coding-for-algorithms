/*
https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock

给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。
如果你最多只允许完成一笔交易（即买入和卖出一支股票），设计一个算法来计算你所能获取的最大利润。
注意你不能在买入股票前卖出股票。

示例 1:
输入: [7,1,5,3,6,4]
输出: 5
解释: 在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，最大利润 = 6-1 = 5 。
     注意利润不能是 7-1 = 6, 因为卖出价格需要大于买入价格。

示例 2:
输入: [7,6,4,3,1]
输出: 0
解释: 在这种情况下, 没有交易完成, 所以最大利润为 0。
*/

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        /*
        提示：动态规划
        令 dp[i] 为从第零天到第 i 天（索引 i）的最大获利，并记录从第零天到第 i 天的股票最低价格 min_prices。
        则状态转移方程为:
        dp[i] = max(dp[i-1], prices[i] - min_prices)
        */
        if (!prices.size())
            return 0;
        int min_price = prices[0];
        int dp[prices.size()] = {0};
        for (int i = 1; i < prices.size(); ++i)
        {
            if (prices[i] < min_price)
                min_price = prices[i];
            dp[i] = max(dp[i - 1], prices[i] - min_price);
        }
        return dp[prices.size() - 1];
    }

    //方法二，自动状态机：参照 leetcode123(本文件夹下 main123, 或者123-maxProfit3.py)
    int maxProfit2(vector<int> &prices)
    {
        if (prices.empty())
            return 0;
        //进行初始化，第一天 s1 将股票买入，其他状态全部初始化为最小值
        int s0 = 0;
        int s1 = INT_MIN; // int s1 = 0x80000000;
        int s2 = 0;

        for (int i = 0; i < prices.size(); ++i)
        {
            s1 = max(s1, s0 - prices[i]); //买入价格更低的股
            s2 = max(s2, s1 + prices[i]); //卖出当前股，或者不操作
        }
        return s2 - s0;
    }
};