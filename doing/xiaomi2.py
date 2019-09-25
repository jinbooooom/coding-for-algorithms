"""
给定一个任意组成的数组A，请返回A中最长等差子序列的长度。

例如：
数组A中，如果：
A[0]-A[1]==A[1]-A[2]==A[2]-A[3]
那么A[0]，A[1]，A[2]和A[3]组成一个等差数列，组成一个最长4的等差数列。
示例 1：
输入：1,3,5,12
输出：3
解释：整个数组是公差为 3 的等差数列。

示例 2：
输入：9,4,7,2,10
输出：3
解释：
最长的等差子序列是 4,7,10

示例 3：
输入：20,1,15,3,10,5,8
输出：4
解释：
最长的等差子序列是 20,15,10,5
"""
class Solution:
    def main(self, arr):
        size = len(arr)
        if size < 3:
            return size
        max_len = 2
        t_cnt = 2
        for i in range(size):
            for j in range(i + 1, size):
                cnt = 2
                if j == i+1:
                    gongcha = arr[i] - arr[j]
                jj = j
                for k in range(j + 1, size):
                    if arr[jj] + gongcha == arr[k]:
                        cnt += 1
                        jj = k
                if cnt > max_len:
                    max_len = cnt
        return max_len



        """
        for i in range(2, size):
            cnt = 1
            for gap in range(1, i + 1):
                for j in range(i - gap, -1, -1):
                    if j == i - gap:
                        gongcha = arr[i] - arr[j]
                        this = arr[j + gap]
                        next = arr[j]
                    else:
                        this = arr[j + gap]
                        next = arr[j]
                    if this - next == gongcha:
                        cnt += 1
                if cnt > max_len:
                    max_len = cnt
                cnt = 0
        return max_len
        """


if __name__ == "__main__":
    f = Solution()
    arr = list(map(int, input().strip().split(',')))
    print(f.main(arr))