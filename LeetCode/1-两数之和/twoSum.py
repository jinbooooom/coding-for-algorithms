"""
https://leetcode-cn.com/problems/two-sum

给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。
你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。

示例:
给定 nums = [2, 7, 11, 15], target = 9

因为 nums[0] + nums[1] = 2 + 7 = 9
所以返回 [0, 1]
"""
from typing import List


class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        d = {}
        # 如果 nums = [3, 3], 那么 d = {3: 1} 只有一个值
        for value, key in enumerate(nums):
            d[key] = value

        for i, key in enumerate(nums):
            # 如果 nums = [3, 3], target = 6
            # 此时 i = 0, d[3] = 1 不等于 0，仍旧打印 [0, 1]
            if (target - key) in d.keys() and d[target - key] != i:
                return [i, d[target - key]]