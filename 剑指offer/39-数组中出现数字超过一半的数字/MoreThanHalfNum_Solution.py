# -*- coding:utf-8 -*-
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
        法二：同法一，但不需要用字典存储每个数字出现的次数，只需要用两个变量就可以了。
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
        仿照快排里的 partition，找任意第 k 大的数字。
        数组中出现次数超过一半的数字，必然是中位数，然后找中位数就好了。
        """
        # write code here
        pass


if __name__ == "__main__":
    num = [1, 2, 3, 2, 2, 2, 5, 4, 2]
    f = Solution()
    print(f.MoreThanHalfNum_Solution2(num))


