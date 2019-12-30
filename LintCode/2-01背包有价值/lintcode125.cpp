/*
有 n 个物品和一个大小为 m 的背包. 给定数组 A 表示每个物品的大小和数组 V 表示每个物品的价值.
装入背包的物品总价值最大是多大?

样例 1:
输入: m = 10, A = [2, 3, 5, 7], V = [1, 5, 2, 4]
输出: 9
解释: 装入 A[1] 和 A[3] 可以得到最大价值, V[1] + V[3] = 9

样例 2:
输入: m = 10, A = [2, 3, 8], V = [2, 5, 8]
输出: 10
解释: 装入 A[0] 和 A[2] 可以得到最大价值, V[0] + V[2] = 10

注意事项
    A[i], V[i], n, m 均为整数
    你不能将物品进行切分
    你所挑选的要装入背包的物品的总大小不能超过 m
    每个物品只能取一次
*/

class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @param V: Given n items with value V[i]
     * @return: The maximum value
     */
    int backPackII(int m, vector<int> &A, vector<int> &V) {
        // write your code here
        int n = A.size();
        if (m <= 0 || A.empty() || V.empty())
            return 0;
        vector<int> dp(m + 1, 0);
        for (int i = 0; i < n; ++i)
            for (int j = m; j >= A[i]; --j)
                dp[j] = max(dp[j], dp[j - A[i]] + V[i]);
        return dp[m];
    }
};