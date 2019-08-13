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


f = Solution()
arr = [1, -2, 3, 10, -4, 7, 2, -5]
print(f.FindGreatestSumOfSubArray(arr))