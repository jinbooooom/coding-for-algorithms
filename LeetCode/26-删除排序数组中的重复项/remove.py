"""
https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array

给定一个排序数组，你需要在原地删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度。
不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。

示例 1:
给定数组 nums = [1,1,2],
函数应该返回新的长度 2, 并且原数组 nums 的前两个元素被修改为 1, 2。
你不需要考虑数组中超出新长度后面的元素。

示例 2:
给定 nums = [0,0,1,1,1,2,2,3,3,4],
函数应该返回新的长度 5, 并且原数组 nums 的前五个元素被修改为 0, 1, 2, 3, 4。
你不需要考虑数组中超出新长度后面的元素。
"""
from typing import List


class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        """
        提示：
        让 this 指向数字第一次出现的位置，next 一直往后加，直到到达最后一个元素。
        如果 next 处的元素与 this 处的元素相同，则 next 自增，this 不动
        如果 next 处的元素与 this 处的元素不同，则让 this+1，并把 next 处的元素放到新的 this 位置处，next 再自增。

        """
        size = len(nums)
        if size < 2:
            return size
        this = 0
        next = 1
        while next < size:
            if nums[this] == nums[next]:
                next += 1
            else:
                this += 1
                nums[this] = nums[next]
                next += 1
        return this + 1
