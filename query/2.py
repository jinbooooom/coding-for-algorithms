

class Solution:
    def main(self, A):
        """
        令 dp[j] 为 A[:j+1] 中，A[j] - A[i] 的最大值，
        则
        dp[j] = max(dp[j-1], A[j] - m)

        :param a:
        :return:
        """
        n = len(A)
        dp = [0] * n
        dp[0] = 0

        m = float('inf')
        for i in range(len(A)):
            m = A[i] if A[i] < m else m
            for j in range(i + 1, len(A)):
                dp[j] = max(dp[j - 1], A[j] - m)
        return dp[-1]


if __name__ == "__main__":
    A = [6, 4, 2, 8, 9, 1]

    f = Solution()
    print(f.main(A))