"""
https://leetcode-cn.com/problems/move-zeroes

给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。

示例:
输入: [0,1,0,3,12]
输出: [1,3,12,0,0]

说明:
    必须在原数组上操作，不能拷贝额外的数组。
    尽量减少操作次数。
"""
from typing import List


class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        提示：双指针
        指针 p1 指向可以被覆盖的位置，指针 p2 指向当前遍历到的位置
        p2 每次遇到零就自增，p1 不变；
        遇到非零，就将当前值覆盖掉 p1 位置的元素，然后 p1, p2 同时自增。
        当 p2 到达数组尾部的时候，p1 到数组尾部的元素再全部填充零

        Do not return anything, modify nums in-place instead.
        """
        size = len(nums)
        p1 = p2 = 0
        while p2 < size:
            if nums[p2] != 0:
                nums[p1] = nums[p2]
                p1 += 1
                p2 += 1
            else:
                p2 += 1
        while p1 < size:
            nums[p1] = 0
            p1 += 1

    def moveZeroes2(self, nums: List[int]) -> None:
        """
        提示：冒泡排序
        相邻元素比较，使零沉底，几轮交换下来，零就在数组尾部。
        """
        pass