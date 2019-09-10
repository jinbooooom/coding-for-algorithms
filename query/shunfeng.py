"""
给定两个长度均为n的排列A和B。现想要交换A中元素的位置，使其变成B。
已知交换A中第i个元素和第j个元素所需要的代价为 | i−j |，问：A变成B的最小代价是多少？

输入
第一行一个整数n，表示排列的长度。(1 <= n <= 200000)
第二行n个整数，中间用空格隔开，表示排列A。
保证1 <= Ai <= n，且不存在任意的i ≠ j，Ai == Aj。
 第三行n个整数，中间用空格隔开，表示排列B。保证1 <= Bi <= n，且不存在任意的i ≠ j，Bi == Bj。

输出
一个整数，表示A变成B的最小代价。

样例输入
4
4 2 1 3   3, 2, 4, 1
3 2 4 1   1, 2, 3, 4
样例输出
3
"""
class Solution():
    def min_swap(self, s1, s2):
        if len(s1) != len(s2) or not s1 or not s2:
            return None
        s = self.pross(s1, s2)
        cost = 0
        return self.process(s, cost, s1)

    def process(self, s, cost, s1):
        gapmin = len(s)
        swap_index = 0
        for i in range(len(s)):
            if gapmin > abs(s[i] - i - 1) > 0:
                swap_index = i
                swap_index2 = s[swap_index] - 1
                gapmin = abs(swap_index2 - swap_index)
        if gapmin == len(s):
            return cost
        s[swap_index], s[swap_index2] = s[swap_index2], s[swap_index]
        s1[swap_index], s1[swap_index2] = s1[swap_index2], s1[swap_index]
        cost += gapmin
        print("交换索引{}, {}处的数字，s1转变为{}，总代价为{}".format(swap_index2, swap_index, s1, cost))
        return self.process(s, cost, s1)

    def pross(self, s1, s2):
        """
        样例输入
        s1 = [4 2 1 3]
        s2 = [3 2 4 1]
        return s = [3, 2, 4, 1]
        """
        s = [0] * len(s2)
        for i in range(len(s2)):
            s[s2[i]-1] = s1[i]
        # print(s)
        return s

if __name__ == "__main__":
    ss1 = [4, 2, 1, 3]
    ss2 = [3, 2, 4, 1]

    s1 = [3, 2, 5, 1, 4]
    s2 = [1, 3, 2, 4, 5]
    f = Solution()
    print(s1,"--->", s2)
    print(f.min_swap(s1, s2))
