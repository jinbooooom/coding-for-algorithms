"""
把只包含质因子2、3和5的数称作丑数（Ugly Number）。
例如6、8都是丑数，但14不是，因为它包含质因子7。
习惯上我们把1当做是第一个丑数。求按从小到大的顺序的第N个丑数。
"""


class Solution:
    def GetUglyNumber_Solution(self, index):
        """
        丑数只包含质因子2、3和5，那么将之前已经计算的丑数与2、3、5相乘，得到的数必定是丑数，取得到的最小的数。
        """
        if index < 1:
            return 0
        res = [0] * index
        res[0] = 1
        id2 = id3 = id5 = 0
        for i in range(1, index):
            res[i] = min(res[id2] * 2, res[id3] * 3, res[id5] * 5)
            if res[i] == res[id2] * 2:
                id2 += 1
            if res[i] == res[id3] * 3:
                id3 += 1
            if res[i] == res[id5] * 5:
                id5 += 1
        return res[-1]


if __name__ == "__main__":
    f = Solution()
    f.GetUglyNumber_Solution(int(input()))