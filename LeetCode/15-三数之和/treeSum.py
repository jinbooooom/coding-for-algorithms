"""
找出所有满足条件且不重复的三元组。

注意：答案中不可以包含重复的三元组。
例如, 给定数组 nums = [-1, 0, 1, 2, -1, -4]，

满足要求的三元组集合为：
[
[-1, 0, 1],
[-1, -1, 2]
]
"""
from typing import List


class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        """
        算法流程：
        对数组进行排序。
        遍历排序后的数组：
        若 nums[i] > 0：因为已经排序好，所以后面不可能有三个数加和等于 0，直接返回结果。
        对于重复元素：跳过，避免出现重复解
        令左指针 pl = i+1，右指针 pr = n−1，当 pl < pr 时，执行循环：
            若 num[i] + nums[pl] + nums[pr] 大于 0，说明 nums[pr] 太大，pr 左移;
            若 num[i] + nums[pl] + nums[pr] 小于 0，说明 nums[pl] 太小，pl 右移
        """
        n = len(nums)
        res = []
        if not nums or n < 3:
            return []
        nums.sort()
        res = []
        for i in range(n):
            if nums[i] > 0:
                return res
            if i > 0 and nums[i] == nums[i - 1]:
                continue
            pl = i + 1
            pr = n - 1
            while pl < pr:
                if nums[i] + nums[pl] + nums[pr] == 0:
                    res.append([nums[i], nums[pl], nums[pr]])
                    while pl < pr and nums[pl] == nums[pl + 1]:
                        pl += 1
                    while pl < pr and nums[pr] == nums[pr - 1]:
                        pr -= 1
                    pl += 1
                    pr -= 1
                elif nums[i] + nums[pl] + nums[pr] > 0:
                    pr -= 1
                else:
                    pl += 1
        return res
