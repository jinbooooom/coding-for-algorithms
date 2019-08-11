# -*- coding:utf-8 -*-
"""
题目：
输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，例如，如果输入如下 4 X 4 矩阵：
1   2   3   4
5   6   7   8
9  10  11  12
13 14  15  16

则依次打印出数字

1, 2, 3, 4, 8, 12, 16, 15, 14, 13, 9, 5, 6, 7, 11, 10.
"""


class Solution:
    # matrix类型为二维列表，需要返回列表
    def printMatrix(self, matrix):
        """
        思路：
        使用 p1, p2代表矩阵的左上角和右下角坐标，
        以左上角为起点，先移动到右上角，再到右下角，再到左下角，再到左上角的下面一个位置，如下面箭头所示：

        >  >  >  >  >
        ^           v
        ^           v
        <  <  <  <  <

        在最后一圈考虑几个特例：

        >  >  >  >  >       >                     >   >
        <  <  <  <  v       v       >  >  >       ^   v
                            v                     <   v

            (a)            (b)        (c)          (d)
        """
        # write code here

        if matrix is None:
            return None
        rows = len(matrix)
        cols = len(matrix[0])
        p1 = (0, 0)
        p2 = (rows - 1, cols - 1)
        arr = []
        self.circle(matrix, p1, p2, arr)
        while p2[1] - p1[1] > 1 and p2[0] - p1[0] > 1:
            p1 = (p1[0] + 1, p1[1] + 1)
            p2 = (p2[0] - 1, p2[1] - 1)
            self.circle(matrix, p1, p2, arr)
        return arr

    def circle(self, M, p1, p2, arr):
        for col in range(p1[1], p2[1] + 1):
            arr.append(M[p1[0]][col])
        for row in range(p1[0] + 1, p2[0] + 1):
            arr.append(M[row][p2[1]])
        if p2[0] > p1[0]:  # 满足此条件，才会发生 (a) 中从右下角到左下角移动的情况
            for col in range(p2[1] - 1, p1[1] - 1, -1):
                arr.append(M[p2[0]][col])
        if p2[1] > p1[1]:  # 满足此条件， 才会发生 (d) 中从左下角到左上角移动的情况，不然 (b) 中路径也会执行 for 里面的语句
            for row in range(p2[0] - 1, p1[0] + 1 - 1, -1):
                arr.append(M[row][p1[0]])







