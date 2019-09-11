class Solution:
    def main(self, array):
        if not array:
            return 0
        dp = [-1] * len(array)
        for i in range(len(array)):
            if i == 0 or dp[i - 1] <= 0:
                dp[i] = array[i]
            else:
                dp[i] = dp[i - 1] + array[i]
        return max(dp)


if __name__ == "__main__":
    f = Solution()
    arr = list(map(int, input().strip().split()))
    print(f.main(arr))