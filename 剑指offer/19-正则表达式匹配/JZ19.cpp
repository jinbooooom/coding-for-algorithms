class Solution {
public:
    bool match(char* str, char* pattern)
    {
        if (str == nullptr || pattern == nullptr)
            return false;
        else if (*str != '\0' && *pattern == '\0')
            return false;
        else if (*str == '\0' && *pattern == '\0')
            return true;
        // 当 pattern 不是指向 "\0" 的时候
        if (*(pattern + 1) == '*')    // pattern 第二个字符为 '*'，情况考虑复杂
        {
            if (*str == *pattern || (*pattern == '.' && *str != '\0'))
                return match(str + 1, pattern + 2)     // aab 和 a*a*b
                        || match(str + 1, pattern)     // aab 和 a*b
                        || match(str, pattern + 2);    // aab 和 a*a*a*a*a*b
            else // *str 与 *pattern 不匹配，如 bac 和 a*bac
                return match(str, pattern + 2);
        }
        else if (*str == *pattern || (*pattern == '.' && *str != '\0'))
            return match(str + 1, pattern + 1);
        else
            return false;
    }
};