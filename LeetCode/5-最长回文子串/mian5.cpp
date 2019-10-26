class Solution {
public:
    string longestPalindrome(string s) {
        int size = s.size();
        if (size <= 1)
            return s;
        int dp[size][size] = {false};
        int longest_len = 1, cur_len = 0;
        int left = 0;

        for (int r = 1; r < size; ++r)
            for (int l = 0; l < r; ++l)
                if ((s[l] == s[r]) && (r - l <= 2 || dp[l+1][r-1]))
                {
                    dp[l][r] = true;
                    cur_len = r -l + 1;
                    if (cur_len > longest_len)
                    {
                        longest_len = cur_len;
                        left = l;
                    }
                }
        return s.substr(left, longest_len);
    }
};