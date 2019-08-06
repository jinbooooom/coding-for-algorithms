# -*- coding:utf-8 -*-
"""
在一个二维数组中（每个一维数组的长度相同），
每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
"""


class Solution:
    # array 二维列表
    def find(self, target, array):
        """
        提示：
        将 target 与数组右上角所在的元素比较：
            相等：返回找到了
            小于：该元素所在的那一列里肯定是找不到的，只会存在于该元素左边所在的矩形区域
            大于：该元素所在的那一行里肯定是找不到的，只会存在于该元素下方所在的矩形区域
        """
        # write code here

        if not array:
            return False
        row = 0
        col = len(array[0]) - 1
        while col >= 0 and row <= len(array) - 1:
            if array[row][col] == target:
                return True
            if array[row][col] > target:
                col -= 1
            else:
                row += 1
        return False
