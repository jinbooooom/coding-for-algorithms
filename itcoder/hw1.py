# -*- coding:utf-8 -*

class Solution:
        def game2048(self, nums):
            size = 10
            cnt = 0
            while(True):
                #print("【1】", nums)
                if nums[size - 1] >= 2:
                    return cnt + 1
                for i in range(size-2, -1, -1):  # 【2】
                    if nums[i] >= 2:    # 【3】
                        nums[i] -= 2
                        cnt += 1
                        if i < size-1:
                            nums[i + 1] += 1
                        else:
                            return cnt
                        #print("【3】", nums)
                        break
                    #print("【2】", nums)


if __name__ == "__main__":
    f = Solution()
    elems = [2, 4, 8, 16, 32, 64, 128, 256, 512, 1024]
    t = int(input().strip())
    for i in range(t):
        nums = list(map(int, input().strip().split()))
        # nums = [2, 1, 1, 1, 1, 1, 1, 1, 1, 1]
        target = 2048
        res = f.game2048(nums)
        print(res)














