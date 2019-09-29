"""
https://leetcode-cn.com/problems/rotate-array

给定一个数组，将数组中的元素向右移动 k 个位置，其中 k 是非负数。

示例 1:
输入: [1,2,3,4,5,6,7] 和 k = 3
输出: [5,6,7,1,2,3,4]
解释:
向右旋转 1 步: [7,1,2,3,4,5,6]
向右旋转 2 步: [6,7,1,2,3,4,5]
向右旋转 3 步: [5,6,7,1,2,3,4]

示例 2:
输入: [-1,-100,3,99] 和 k = 2
输出: [3,99,-1,-100]
解释:
向右旋转 1 步: [99,-1,-100,3]
向右旋转 2 步: [3,99,-1,-100]

说明:
    尽可能想出更多的解决方案，至少有三种不同的方法可以解决这个问题。
    要求使用空间复杂度为 O(1) 的原地算法。

"""
from typing import List


class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        提示：切片
        但这个空间复杂度不是 O(1)
        Do not return anything, modify nums in-place instead.
        """
        k %= len(nums)
        nums[:] = nums[-k:] + nums[:-k]

    def rotate2(self, nums: List[int], k: int) -> None:
        """
        提示：反转法
        假设 nums：[1, 2, 3, 4, 5]，k = 2
        反转 nums: [5, 4, 3, 2, 1]
        反转前 k 个，nums: [4, 5, 3, 2, 1]
        反转区间 [k, size) 部分，nums: [4, 5, 1, 2, 3]
        """
        nums[:] = nums[::-1]
        nums[:k] = nums[:k][::-1]
        nums[k:] = nums[k:][::-1]

    def rotate3(self, nums: List[int], k: int) -> None:
        """
        提示：环状替换
        假设 nums：[1, 2, 3, 4, 5]，k = 2
        那么元素的替换方式为：1->3->5->2->4->1，最后替换 size 次就得到旋转数组。
        假设 nums: [1, 2, 3, 4], k = 2
        那么元素的替换方式为：1->3->1->3->1->3，会一直循环替换，那么需要记录替换开始时的索引位置 start，
        如果要替换的元素索引又回到了最开始的 start，说明是循环替换，需要跳出该循环，然后从 start 后面一个元素重新开始环状替换。
        始终要判断替换的次数不能能超过 size 次
        """
        size = len(nums)
        if size < 2 or k <= 0:
            return None
        cnt = 0
        while cnt < size:
            for i in range(k):
                if cnt >= size:
                    break
                start = i
                p_prev = i
                p_next = (p_prev + k) % size
                e_prev = nums[p_prev]
                e_next = nums[p_next]
                while p_next != start and cnt < size:
                    nums[p_next] = e_prev
                    cnt += 1
                    p_prev, p_next = p_next, (p_next + k) % size
                    e_prev, e_next = e_next, nums[p_next]

                nums[p_next] = e_prev
                cnt += 1
