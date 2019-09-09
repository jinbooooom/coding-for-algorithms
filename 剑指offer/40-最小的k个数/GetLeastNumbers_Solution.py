# -*- coding:utf-8 -*-
"""
题目:
输入n个整数，找出其中最小的K个数。
例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4,。
"""

class Solution:
    def GetLeastNumbers_Solution(self, tinput, k):
        """
        基于快速排序的 partition。 将数组 input 划分成两部分：
        input[: k] 都小于第 k 小的数，input[k+1:] 都大于第 k 小的数，
        但 input[: k] 部分是无序的，牛客网返回的最小的 k 个数都是有序输出。
        """
        # write code here
        if k > len(tinput) or k == 0:
            return []
        return sorted(self.kth_partition(tinput, 0, len(tinput) - 1, k)[:k])

    def kth_partition(self, arr, start, end, k):
        left = start
        right = end
        key = arr[start]
        while right > left:
            while right > left and arr[right] >= key:
                right -= 1
            if right > left:
                arr[left] = arr[right]
                left += 1
            while right > left and arr[left] <= key:
                left += 1
            if right > left:
                arr[right] = arr[left]
                right -= 1

        arr[left] = key
        if k-1 == left:
            return arr
        elif k-1 > left:
            return self.kth_partition(arr, left+1, end, k)
        else:
            return self.kth_partition(arr, start, left-1, k)


if __name__ == "__main__":
    f = Solution()
    arr = [6, 8, 5, 3, 9, 2, 7, 4, 1]
    arr2 = [1, 1, 1, 1, 1, 1, 1, 1, 1, 1]
    k = 5
    L = f.GetLeastNumbers_Solution(arr2, k)
    print(L[:k])

