/*
给定一个数组，它的第 i 个元素是一支给定的股票在第 i 天的价格。
设计一个算法来计算你所能获取的最大利润。你最多可以完成两笔交易。
注意: 你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

示例 1:
输入: [3,3,5,0,0,3,1,4]
输出: 6
解释: 在第 4 天（股票价格 = 0）的时候买入，在第 6 天（股票价格 = 3）的时候卖出，这笔交易所能获得利润 = 3-0 = 3 。
     随后，在第 7 天（股票价格 = 1）的时候买入，在第 8 天 （股票价格 = 4）的时候卖出，这笔交易所能获得利润 = 4-1 = 3 。

示例 2:
输入: [1,2,3,4,5]
输出: 4
解释: 在第 1 天（股票价格 = 1）的时候买入，在第 5 天 （股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5-1 = 4 。
     注意你不能在第 1 天和第 2 天接连购买股票，之后再将它们卖出。
     因为这样属于同时参与了多笔交易，你必须在再次购买前出售掉之前的股票。

示例 3:
输入: [7,6,4,3,1]
输出: 0
解释: 在这个情况下, 没有交易完成, 所以最大利润为 0。
*/

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
