/*
https://leetcode-cn.com/problems/longest-substring-without-repeating-characters

给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。

示例 1:
输入: "abcabcbb"
输出: 3
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。

示例 2:
输入: "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。

示例 3:
输入: "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
*/


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        /*
        提示：
        动态规划：设 f(i) 表示以索引 i 结尾的不包含重复字符的子字符串的最长长度

        如果 s[i] 在闭区间 [0, i-1] 没有出现过，那么 f(i) = f(i-1) + 1；
        如果 s[i] 在闭区间 [0, i-1] 出现过，设 d 为 s[i] 这次出现的位置与上次出现的位置的距离，
        此时有两种情况：
            当 d <= f(i-1)，说明 s[i] 上次出现的位置是在 f(i-1) 对应的不重复最长子串内，因此 f(i) = d；
            当 d > f(i-1)，说明 s[i] 上次出现的位置在 f(i-1) 对应的最长不重复子串之外，此时 f(i) = f(i-1) + 1

        如果得到字符上次出现时的位置？
        通过一个辅助数组（或者哈希）存放字符的上次位置

        */

        if (s.empty())
            return 0;
        vector<int> position(256, -1);  // s 不仅有字母还有其它字符
        vector<int> dp(s.size(), 0);
        dp[0] = 1;
        position[s[0] - '\0'] = 0;  // 下面循环从 1 开始，得提前存好 s[0] 的旧索引 0
        for (int i = 1; i < s.size(); ++i)
        {
            int preIndex = position[s[i] - '\0'];
            int d = i - preIndex;
            if (preIndex < 0 || d > dp[i - 1])
                dp[i] = dp[i - 1] + 1;
            else if (d <= dp[i - 1])
                dp[i] = d;
            position[s[i] - '\0'] = i;
        }
        int maxLength = 0;
        for (int i = 0; i < dp.size(); ++i)
            maxLength = max(maxLength, dp[i]);
        return maxLength;
    }
};