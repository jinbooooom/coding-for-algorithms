# -*- coding:utf-8 -*-
"""
https://leetcode-cn.com/problems/unique-paths

一个机器人位于一个 m x n 网格的左上角，机器人每次只能向下或者向右移动一步。
机器人试图达到网格的右下角，问总共有多少条不同的路径？

示例 1:
输入: m = 3, n = 2
输出: 3
解释:
从左上角开始，总共有 3 条路径可以到达右下角。
1. 向右 -> 向下 -> 向下
2. 向下 -> 向右 -> 向下
3. 向下 -> 向下 -> 向右

示例 2:
输入: m = 7, n = 3
输出: 28

"""

class Solution:
    def __init__(self):
        self.dp = {(0, 0): 1}

    def uniquePaths(self, m: int, n: int) -> int:
        """
        提示：动态规划求解
        令 dp[(i, j)] 是从左上角 (0, 0) 到达 (i, j) 的不同路径数量，
        状态转移方程为：dp[(i, j)] = dp[(i-1, j)] + dp[(i, j-1)]
        注意，对于索引为零的行 dp[(0, j)]，或者索引为零的列 dp[i][0]，由于都是在边界，所以只有一种到达方式。
        """
        if m <= 0 or n <= 0:
            return 0
        # 第 0 行和第 0 列所在的格子，到达的方式只有一种。
        self.dp.update({(0, j): 1 for j in range(1, n)})
        self.dp.update({(i, 0): 1 for i in range(1, m)})
        # 从格子 (1, 1) 开始
        for i in range(1, m):
            for j in range(1, n):
                self.dp[(i, j)] = self.dp[(i - 1, j)] + self.dp[(i, j - 1)]
        return self.dp[(m-1, n-1)]


if __name__ == "__main__":
    f = Solution()
    m, n = 7, 3
    print(f.uniquePaths(m, n))
