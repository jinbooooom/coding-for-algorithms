#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>

using namespace std;

/*
https://leetcode-cn.com/problems/longest-palindromic-subsequence
https://leetcode-cn.com/problems/longest-palindromic-subsequence/solution/dong-tai-gui-hua-si-yao-su-by-a380922457-3/
https://leetcode-cn.com/problems/longest-palindromic-subsequence/solution/zi-xu-lie-wen-ti-tong-yong-si-lu-zui-chang-hui-wen/

给定一个字符串s，找到其中最长的回文子序列。可以假设s的最大长度为1000。

示例 1:
输入:
"bbbab"

输出:
4
一个可能的最长回文子序列为 "bbbb"。

示例 2:
输入:
"cbbd"

输出:
2
*/


class Solution {
public:
    int longestPalindromeSubseq(string s) {
    /*
    令 dp[i][j] 为闭区间 [i, j] 内的最长子序列的长度，那么，
    状态转移方程为：
    dp[i][j] = dp[i + 1][j - 1] + 2                 if s[i] == s[j]
    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1])      if s[i] != s[j]
    */
        if (s.empty())
            return 0;

        int n = s.size();
        vector<vector<int> > dp(n, vector<int>(n, 0));
        for (int i = 0; i < n; ++i)  // 当子串只有一个元素，那么序列必定回文，其长度为 1
            dp[i][i] = 1;

        for (int j = 1; j < n; ++j)
            for (int i = j - 1; i >= 0; --i)  // 因为 dp[i][j] 与 dp[i + 1][j - 1]，dp[i + 1][j]，所以关于 i 的循环得从 j 到 0，先计算大的。
                if (s[i] == s[j])
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                else
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
        return dp[0][n - 1];
    }
};



