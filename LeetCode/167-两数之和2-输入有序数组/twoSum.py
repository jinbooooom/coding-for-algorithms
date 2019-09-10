# -*- coding:utf-8 -*-
"""
https://leetcode-cn.com/problems/two-_sum-ii-input-array-is-sorted/submissions/

给定一个已按照升序排列 的有序数组，找到两个数使得它们相加之和等于目标数。
函数应该返回这两个下标值 index1 和 index2，其中 index1 必须小于 index2。
说明:
返回的下标值（index1 和 index2）不是从零开始的。
你可以假设每个输入只对应唯一的答案，而且你不可以重复使用相同的元素。

示例:
输入: numbers = [2, 7, 11, 15], target = 9
输出: [1, 2]
解释: 2 与 7 之和等于目标数 9 。因此 index1 = 1, index2 = 2 。

"""


class Solution(object):
    def two_sum(self, numbers, target):
        """
        提示：
        左右两个指针 left, right 分别指向首尾元素，_sum 等于 left, right 指向的元素之和。
        _sum 和 target比较，当 _sum 小于 target 时，left 往右走，当 _sum 大于 target 的时候，right 往左走。
        
        :type numbers: List[int]
        :type target: int
        :rtype: List[int]
        """
        left = 0
        right = len(numbers) - 1
        _sum = 0
        while left < right:
            _sum = numbers[left] + numbers[right]
            if _sum < target:
                left += 1
            elif _sum > target:
                right -= 1
            else:
                return [left + 1, right + 1]  # 因为题目中的下标值，指的是第几个数而不是索引

