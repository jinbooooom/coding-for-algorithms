# -*- coding:utf-8 -*-
"""
题目：
在古老的一维模式识别中,常常需要计算连续子向量的最大和,当向量全为正数的时候,问题很好解决。
但是,如果向量中包含负数,是否应该包含某个负数,并期望旁边的正数会弥补它呢？
例如:{6,-3,-2,7,-15,1,2,2},连续子向量的最大和为8(从第0个开始,到第3个为止)。
给一个数组，返回它的最大连续子序列的和(子向量的长度至少是1)。
"""


class Solution:
    def FindGreatestSumOfSubArray(self, array):
        """
        提示：
        方法一：从头到尾逐个累加数组里的数字，如果某次累加的结果为负数，则从下一个元素开始重新累加。
        """
        # write code here
        greatSum = float("-inf")
        curSum = 0
        for x in array:
            if curSum > 0:
                curSum += x
            else:
                curSum = x
            greatSum = max(greatSum, curSum)
        return greatSum


    def FindGreatestSumOfSubArray_back(self, array):
        """
        提示：
        同方法一，但牛客网 python2.7 不支持无穷小 float("-inf")：
        从头到尾逐个累加数组里的数字，如果某次累加的结果为负数，则从下一个元素开始重新累加。
        """
        # write code here
        result = -1
        first = True
        for x in array:
            if result < 0:
                result = x
            else:
                result += x
            if first:
                max = result
                first = False
            else:
                if result > max:
                    max = result
        return max

    def FindGreatestSumOfSubArray2(self, array):
        """
        方法二提示：
        动态规划求解：
        用 f(i) 表示以索引 i 结尾的子数组的最大和，那么我们需要求出 max[f(i)]，其中 i 属于闭区间 [0, n-1]。
        则状态转移方程为：

                 array[i]               if i == 0 or f(i-1) <= 0
        f(i) = /
               \
                f(i-1) + array[i]      if i != 0 and f(i-1) > 0

        """
        dp = [-1] * len(array)
        for i in range(len(array)):
            if i == 0 or dp[i-1] <= 0:
                dp[i] = array[i]
            else:
                dp[i] = dp[i-1] + array[i]
        return max(dp)


f = Solution()
arr = [1, -2, 3, 10, -4, 7, 2, -5]
print(f.FindGreatestSumOfSubArray(arr))
print(f.FindGreatestSumOfSubArray2(arr))