class Solution {
public:
    int cutRope(int number) {
        int *dp = new int[number + 1];
        dp[0] = 0, dp[1] = dp[2] = 1, dp[3] = 2;  // 绳子必须得剪一次
        if (number < 4) return dp[number];
        for (int i = 0; i < 4; ++i)
            dp[i] = i;
        int max = 0;
        for (int i = 4; i <= number; ++i)
        {
            for (int j = 1; j <= i / 2; ++j)
            {
                dp[i] = dp[j] * dp[i - j];
                dp[i] = dp[i] > max ? dp[i] : max;
            }
        }
        return dp[number];
    }
};