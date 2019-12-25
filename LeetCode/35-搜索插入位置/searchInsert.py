# -*- coding:itf-8 -*-
"""
https://leetcode-cn.com/problems/search-insert-position/

给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。
如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
你可以假设数组中无重复元素。

示例 1:
输入: [1,3,5,6], 5
输出: 2

示例 2:
输入: [1,3,5,7,9], 4
输出: 2

示例 3:
输入: [1,3,5,7,9], 6
输出: 3

"""


class Solution(object):
    def searchInsert(self, nums, target):
        """
        提示：
        二分查找，时间复杂度是 O(logn)，注意临界值。
        """
        if target <= nums[0]:
            return 0
        if target > nums[-1]:
            return len(nums)

        left, right = 0, len(nums)-1
        while left <= right:
            mid = (left + right) // 2
            if target < nums[mid]:
                right = mid - 1
            elif target > nums[mid]:
                left = mid + 1
            else:
                return mid
        if target < nums[mid]:
            return mid
        if target > nums[mid]:
            return mid + 1
