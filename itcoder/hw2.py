# -*- coding:utf-8 -*

class Solution:
    def weight(self, nums):
        for x in nums:

    def trans(self, key, pai):
        if pai[1] == "J":  # J
            pai = "J"
        elif pai[0] == "J":   # 大小王
            pass
        else:
            pai = pai[1]  # 其他牌
        return 1 + key.index(pai)

if __name__ == "__main__":
    f = Solution()
    value = [2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 14]
    key = ["1", "2", "3", "4", "5", "6", "7", "8", "9", "J", "Q", "K", "A", "J1", "J2"]
    nums = [0] * 15
    t = int(input().strip())
    elems = []

    for i in range(t):
        elems.append(input().strip())
    real_pai = [f.trans(key, x) for x in elems]
    for x in real_pai:
        nums[x] += 1
    print(nums)
    print(real_pai)


"""
6
C2
D3
S4
C5
C6
C4
"""














