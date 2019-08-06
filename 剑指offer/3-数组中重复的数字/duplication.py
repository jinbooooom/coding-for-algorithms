# -*- coding:utf-8 -*-
"""
题目：
在一个长度为 n 的数组里的所有数字都在 0 到 n-1 的范围内。
数组中某些数字是重复的，但不知道有几个数字是重复的，
也不知道每个数字重复几次。请找出数组中任意一个重复的数字。
例如，如果输入长度为7的数组 {2,3,1,0,2,5,3}，
那么对应的输出是重复的数字 2 或者 3。
"""


class Solution:
    # 这里要特别注意~找到任意重复的一个值并赋值到duplication[0]
    # 函数返回True/False
    def duplicate(self, numbers, duplication):
        """
        提示：
        数组长度是 n，数组元素范围是 0 ~ n-1，如果使 array[index] = index，那就一个萝卜一个坑，没有重复的了。
        """
        # write code here

        if not numbers:
            return False
        for num in numbers:  # 防止越界
            if num < 0 or num > len(numbers):
                return False

        for i in range(len(numbers)):
            while numbers[i] != i:
                if numbers[i] == numbers[numbers[i]]:
                    duplication[0] = numbers[i]
                    return True
                numbers[numbers[i]], numbers[i] = numbers[i], numbers[numbers[i]]
                # numbers[i], numbers[numbers[i]] = numbers[numbers[i]], numbers[i]
                # 下面一句程序无限运行，为什么？
                # 是因为 将 numbers[numbers[i]] 赋给 numbers[i]，
                # 之后 numbers[i] 赋给 numbers[numbers[i]] 中 numbers[i] 已经修改了？

        return False


if __name__ == "__main__":
    # 测试用例
    numberss = [[2, 3, 1, 0, 2, 5, 3],
                [-1, -2, -3],
                [],
                [3, 2, 3, 0],
                [7, 6, 5, 5]]  # 不合输入条件，返回 False

    for numbers in numberss:
        duplication = [False]
        Solution().duplicate(numbers, duplication)
        result = duplication[0]
        print(result)
