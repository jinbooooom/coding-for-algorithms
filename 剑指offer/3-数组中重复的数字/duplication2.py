# -*- coding:utf-8 -*-
"""
题目：
长度为 n+1 的数组里的所有数字的范围是 1~n，不修改数组，找到任意一个重复的数字。
"""


class Solution:
    # 这里要特别注意~找到任意重复的一个值并赋值到duplication[0]
    # 函数返回True/False
    def duplicate(self, numbers, duplication):
        """
        提示：
        法一：创建辅助空间，空间复杂度 O(n)，时间复杂度 O(n)
            创建一个辅助数组 T全部初始化为零，将原数组内的每一个元素 e 复制到 T 中下标等于 e 的位置，即 T[e] = e。
            如果在赋值之前，就发现 T[e] 不为零，则该数字重复。
        法二：二分法，空间复杂度 O(1)，时间复杂度 O(nlogn)
            将数组元素所在区间（不是数组）分为两部分，已知数组范围是 1~n，数组长度 n+1，则必有重复。
            统计数组中在闭区间 [start, mid] 与 [mid，end] 里的元素个数，如果元素个数大于区间长度那必定有重复，
            在该区间内继续使用二分法即可。
        """
        # write code here
        # 二分法

        if not numbers:
            return False
        for num in numbers:  # 防止越界
            if num < 1 or num > len(numbers):
                return False

        start = 1  # 数字的范围是 start~end
        end = len(numbers) - 1
        while end >= start:
            mid = ((end - start) >> 1) + start
            count = self.countRange(numbers, start, mid)
            if start == end:
                if count > 1:
                    duplication[0] = start
                    return True
            if count > mid - start + 1:
                end = mid
            else:
                start = mid + 1
        return False

    def countRange(self, numbers, start, end):
        if not numbers:
            return False
        count = 0
        for number in numbers:
            if start <= number <= end:
                count += 1
        return count


if __name__ == "__main__":
    # 测试用例
    numberss = [[2, 3, 5, 4, 3, 2, 6, 7],
                [-1, -2, -3],
                [],
                [1, 2, 4, 4, 3],
                [7, 6, 5, 5]]

    for numbers in numberss:
        duplication = [False]
        Solution().duplicate(numbers, duplication)
        print(duplication[0])
