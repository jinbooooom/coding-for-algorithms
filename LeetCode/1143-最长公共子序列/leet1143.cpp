#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>

using namespace std;

/*
https://leetcode-cn.com/problems/longest-common-subsequence
https://leetcode-cn.com/problems/longest-common-subsequence/solution/dong-tai-gui-hua-zhi-zui-chang-gong-gong-zi-xu-lie/

给定两个字符串 text1 和 text2，返回这两个字符串的最长公共子序列。

一个字符串的子序列 是指这样一个新的字符串：它是由原字符串在不改变字符的相对顺序的情况下删除某些字符（也可以不删除任何字符）后组成的新字符串。
例如，"ace" 是 "abcde" 的子序列，但 "aec" 不是 "abcde" 的子序列。两个字符串的「公共子序列」是这两个字符串所共同拥有的子序列。

若这两个字符串没有公共子序列，则返回 0。

示例 1:
输入：text1 = "abcde", text2 = "ace"
输出：3
解释：最长公共子序列是 "ace"，它的长度为 3。

示例 2:
输入：text1 = "abc", text2 = "abc"
输出：3
解释：最长公共子序列是 "abc"，它的长度为 3。

示例 3:
输入：text1 = "abc", text2 = "def"
输出：0
解释：两个字符串没有公共子序列，返回 0。
*/

class Solution
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        /*
        令 dp[i][j] 为 text1 的前 i 个字符（含）组成的字符串与 text2 的前 j 个字符（含）组成的字符串的最长公共子序列
        当 text1 中第 i 个字符（索引 i-1）与 text2 中第 j 个字符（索引 j-1）相等时，即
        text[i - 1] == text[j - 1] 时，dp[i][j] = dp[i - 1][j - 1] + 1，
        反之，dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        */
        if (text1.empty() || text2.empty())
            return 0;

        int len1 = text1.size();
        int len2 = text2.size();
        vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));

        for (int i = 1; i <= len1; ++i)
            for (int j = 1; j <= len2; ++j)
                if (text1[i - 1] == text2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        return dp[len1][len2];
    }
};
