# -*- coding:itf-8 -*-
"""
https://leetcode-cn.com/problems/wiggle-sort-ii/
给定一个无序的数组 nums，将它重新排列成 nums[0] < nums[1] > nums[2] < nums[3]... 的顺序。

示例 :
输入: nums = [1, 5, 1, 1, 6, 4]
输出: 一个可能的答案是 [1, 4, 1, 5, 1, 6]

"""

class Solution:
    def wiggleSort(self, nums) -> None:
        """
        提示：
        对数组排完序，如 [1, 2, 3, 4]，将其分成 [1, 2] 和 [3, 4] 两部分，
        每次从这两个子数组中拿出一个数组成新的数组 [1, 3, 2, 4]。

        但对于实例 [4, 5, 5, 6], 将其分成 [4, 5], [5, 6] 两部分，
        每次从这两个子数组中拿出一个数组成新的数组 [4, 5, 5, 6]。不满足摆动排序。
        我们可以对该实例逆序，得到 [6, 5, 5, 4],将其分成 [5, 4], [6, 5] 两部分，
        这样中间一段重复的数字 5 在左边数组中是第一个用到，在右边数组是最后一个用到，因此在新的数组中它们被分开了。
        每次从这两个子数组中拿出一个数组成新的数组 [5, 6, 4, 5]。满足摆动排序。

        Do not return anything, modify nums in-place instead.
        """
        nums.sort(reverse=True)
        mid = len(nums) // 2
        nums[1::2], nums[0::2] = nums[:mid], nums[mid:]