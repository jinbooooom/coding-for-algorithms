"""
https://leetcode-cn.com/problems/contains-duplicate
https://leetcode-cn.com/problems/contains-duplicate/solution/cun-zai-zhong-fu-de-yuan-su-python3ji-he-fa-by-pan/

给定一个整数数组，判断是否存在重复元素。
如果任何值在数组中出现至少两次，函数返回 true。
如果数组中每个元素都不相同，则返回 false。

示例 1:
输入: [1,2,3,1]
输出: true

示例 2:
输入: [1,2,3,4]
输出: false

示例 3:
输入: [1,1,1,3,3,4,3,2,4,2]
输出: true

"""
from typing import List


class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        """
        提示：集合 set()
        """
        return len((set(nums))) != len(nums)

    def containsDuplicate2(self, nums: List[int]) -> bool:
        """
        提示：哈希表
        如果后面的数在哈希表里出现过，那必有重合
        """
        dic = {}
        for i in nums:
            if dic.get(i):
                return True
            dic[i] = 1
        return False

    def containsDuplicate2(self, nums: List[int]) -> bool:
        """
        提示：排序
        排序的列表，重合的元素必相邻
        """
        nums.sort()
        for i in range(len(nums) - 1):
            if nums[i + 1] == nums[i]:
                return True
        return False



