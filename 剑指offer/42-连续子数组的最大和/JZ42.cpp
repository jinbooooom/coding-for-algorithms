/*
题目：
在古老的一维模式识别中,常常需要计算连续子向量的最大和,当向量全为正数的时候,问题很好解决。
但是,如果向量中包含负数,是否应该包含某个负数,并期望旁边的正数会弥补它呢？
例如:{6,-3,-2,7,-15,1,2,2},连续子向量的最大和为8(从第0个开始,到第3个为止)。
给一个数组，返回它的最大连续子序列的和(子向量的长度至少是1)。
*/

class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        /*
        提示：
        从头到尾逐个累加数组里的数字，如果某次累加的结果为负数，则从下一个元素开始重新累加。

        int min = 0x80000000;  // -2147483648 = 2^31
	    int max = 0x7FFFFFFF;  // 2147483647 = 2^31 - 1
        */
        int greatSum = 0x80000000;
        int curSum = 0;
        for (int i = 0; i < array.size(); ++i)
        {
            if (curSum > 0)
                curSum += array[i];
            else
                curSum = array[i];
            greatSum = greatSum > curSum ? greatSum : curSum;
        }
        return greatSum;
    }

    int FindGreatestSumOfSubArray2(vector<int> array) {
        /*
        提示：
        动态规划求解：
        用 f(i) 表示以索引 i 结尾的子数组的最大和，那么我们需要求出 max[f(i)]，其中 i 属于闭区间 [0, n-1]。
        则状态转移方程为：

                 array[i]               if i == 0 or (i > 0 and f(i-1) <= 0)
        f(i) = /
               \
                f(i-1) + array[i]      if i != 0 and f(i-1) > 0
        */
        int length = array.size();
        vector<int> dp(length, -1);
        for (int i = 0; i < length; ++i)
        {
            if (i == 0 || (i > 0 && dp[i-1] <= 0))
                dp[i] = array[i];
            else if (i > 0 && dp[i-1] > 0)
                dp[i] = dp[i-1] + array[i];
        }

        int m = -1;
        for (int i = 0; i < length; ++i)
            m = m >= dp[i] ? m : dp[i];
        return m;
    }
};