# -*- coding:utf-8 -*-
"""
题目：
把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
输入一个非减排序的数组的一个旋转，输出旋转数组的最小元素。
例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。
NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。
"""


class Solution:
    def minOfRotatingArray(self, L):
        """
        提示：
        数组旋转后，会以最小数字为分界线，分成两部分，且这两部分均非减排序。
        如旋转数组 [3,4,5,1,2] 以 1 为分界线，分成两部分 [3,4,5]，[1,2]。
        使 P1，P2 分别为旋转数组 L 的起始或末尾元素索引，求 P1，P2 的中点 mid，
        若 L[P1] <= L[mid]，则 l[mid] 属于左部分，再在 L[mid:P2] 中用同样的策略寻找最小数；
        若 L[mid] < L[P2]，则 L[mid] 属于右部分，再在 L[P1:mid+1] 中用同样的策略寻找最小数。
        存在特例 L[p1] == L[mid] == L[mid]，没有办法，只能顺序查找。
        """
        # write code here

        if not len(L):
            return 0
        if L[0] < L[-1]:
            # 把非减排序的数组 L 开头的若干个元素搬到数组尾部，那么变动后的数组尾部的元素 L[-1] <= L[0] 是合理的，
            # 若 L[0] < L[-1]，则说明是把 L 开头的 0 个元素搬到数组尾部（即 L 未旋转），此时 L[0] 即最小。
            return L[0]

        P1 = 0
        P2 = len(L) - 1
        while L[P2] <= L[P1]:
            if P2 - P1 == 1:  # 此时，P1 是左部分数组最后一个的索引，P2 是右部分数组开始元素的索引
                mid = P2
                break
            mid = (P1 + P2)//2
            if L[P1] == L[mid] and L[mid] == L[P2]:
                m = L[P1]
                for i in L[P1+1:P2+1]:
                    if m > i:
                        m = i
                return m
            if L[mid] >= L[P1]:
                P1 = mid
            else:
                P2 = mid
        return L[mid]


if __name__ == "__main__":
    L = [[3,4,5,1,2],
         [2,2,2,2,2],
         [2,3,1,2,2],
         [1,2,3,4,5],
         [1,0,1,1,1],
         [1,1,1,0,1],
         ]
    f = Solution()
    for l in L:
        print(l)
        print('min:', f.minOfRotatingArray(l))
