/*
把长度为 n 的绳子剪成 m 段，m, n 均为整数（可以剪零刀），问 m 小段绳子长度之积最大为多少？
比如：
长度为 8 的绳子可以剪成 3，3，2 三段，其积最大为 18。
长度为 3 的绳子不剪，其积最大为 3。

【注意】
牛客网上的题意是绳子必须得剪一次，所以长度为 3 的绳子其积最大为 2（剪成长度为 1 和 2 的两段）

C++ 代码是绳子至少剪一次的实现，同文件夹下 Python 代码是绳子可以不剪的实现
*/

class Solution
{
public:
    int cutRope(int number)
    {
        int *dp = new int[number + 1];
        dp[0] = 0, dp[1] = dp[2] = 1, dp[3] = 2; // 绳子必须得剪一次
        if (number < 4)
            return dp[number];
        for (int i = 0; i < 4; ++i) // 当 number >= 4 的时候，dp[0~3的部分] 不剪比剪要好
            dp[i] = i;
        int max = 0;
        for (int i = 4; i <= number; ++i)
        {
            // 对于一段长度为 i 的绳子，第一刀剪 j 长度，则 f(i) = max(f(j) * f(i-j))，
            // 和第一刀剪 i-j 长度，第二刀剪 j 长度本质上是一样的
            for (int j = 1; j <= i / 2; ++j)
            {
                dp[i] = dp[j] * dp[i - j];
                max = dp[i] > max ? dp[i] : max;
                dp[i] = max;
            }
        }
        return dp[number];
    }
};

#include <iostream>

int main()
{
    Solution s;
    std::cout << s.cutRope(1) << " "
              << s.cutRope(5) << " "
              << s.cutRope(6) << " "
              << s.cutRope(7) << " "
              << s.cutRope(8) << " " << std::endl;
}