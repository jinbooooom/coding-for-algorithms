class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0;
        for (int j = 0; j < t.size(); ++j)
            if (i < s.size())
            {
                if (s[i] == t[j])
                    i++;
            }  // 花括号别省，不然以为下面的 else 是第二个 if 的。
            else
                break;
        return i == s.size();
    }
};