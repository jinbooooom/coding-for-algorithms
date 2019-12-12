# -*- coding:utf-8 -*-
"""
数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。
由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。
如果不存在则输出0。
"""


class Solution:

    def MoreThanHalfNum_Solution1(self, numbers):
        """
        法一：
        统计 numbers 中每个数字出现的次数，存到字典中。
        """
        d = {}
        mcnt = 0
        mkey = 0
        for num in numbers:
            d[num] = d[num] + 1 if num in d else 1
        for k in d:
            if d[k] > mcnt:
                mcnt = d[k]
                mkey = k
        return mkey if mcnt > len(numbers) // 2 else 0

    def MoreThanHalfNum_Solution2(self, numbers):
        """
        法二：Boyer-Moore 投票算法
        """
        mcnt = 0
        mkey = 0
        for num in numbers:
            if mcnt > 0:
                if num == mkey:
                    mcnt += 1
                else:
                    mcnt -= 1
            else:
                mkey = num
                mcnt = 1
        # 考虑实例 [1, 2, 3, 2, 4, 2, 5, 2, 3]
        # 当输入的数组中不存在一个出现次数超过总次数一半的数字时，找到的 mkey 就是不需要的，
        # 这时就要判断 mkey 的次数是否真的超过总次数的一半了。
        return mkey if numbers.count(mkey) > len(numbers) // 2 else 0

    def MoreThanHalfNum_Solution3(self, numbers):
        """
        法三：
        仿照快排里的 partition，找任意第 k 小的数字。
        数组中出现次数超过一半的数字，必然是中位数，然后找中位数就好了。
        """
        # write code here
        mkey = self.kthmin(numbers, len(numbers)//2)
        return mkey if numbers.count(mkey) > len(numbers) // 2 else 0

    def kthmin(self, arr, k):
        """
        在数组 arr 中找第 k 小数，k = 0 为找最小的数字。
        对比一下这种写法与《40-最小的 k 个数》中的函数 kth_partition 在处理上的异同
        """
        key = arr[0]
        arrLeft = [x for x in arr if x < key] + [x for x in arr if x == key][:-1]
        arrRight = [x for x in arr if x > key]
        indexKey = len(arrLeft)
        if k == indexKey:
            return key
        elif k > indexKey:
            return self.kthmin(arrRight, k - indexKey - 1)
        else:
            return self.kthmin(arrLeft, k)


if __name__ == "__main__":
    num = [1, 3, 4, 5, 2, 2, 2, 2, 2]
    f = Solution()
    # print(f.MoreThanHalfNum_Solution3(num))
    print(f.kthmin(num, len(num)//2))


