class Solution {
public:
    int strStr(string haystack, string needle) {
        if (!needle.size())
            return 0;
        if (!haystack.size())// || needle.size() > haystack.size())
            return -1;

        int i = 0, j = 0;

        while (i < int(haystack.size() - needle.size() + 1))
        //haystack.size() - needle.size() + 1是无符号整型，
        //有符号与无符号比较，自动把有符号转换成无符号
        {
            //cout << i << ' ' << haystack.size() << ' ' << needle.size() << ' ' << haystack.size() - needle.size() + 1 << endl;
            while (j  < needle.size())
            {
                if (haystack[i] != needle[j])
                {
                    i = i - j + 1;
                    j = 0;
                    break;
                }
                else
                {
                    ++i;
                    ++j;
                }
            }
            if (j == needle.size())
            return i - j;
        }
        return -1;
    }
};