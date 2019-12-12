// 返回索引的形式：例如 haystack:“abcde”，needle:”bcd“，返回 1
int strStr(string haystack, string needle) {
        if (!needle.size())
            return 0;
        if (!haystack.size())
            return -1;

        int i = 0, j = 0;

    	// haystack.size() - needle.size() + 1是无符号整型，
        // 有符号与无符号比较，自动把有符号转换成无符号
        while (i < int(haystack.size() - needle.size() + 1))
        {
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


// 返回指针的形式:例如 src:"abcdef"，sub:"cde"，
// 那么 strstr(src, sub) 会返回 src 中的字符 'c' 的地址，打印出来就是 "cdef"
// 如果想得到偏移量（索引），让 strstr 的返回值减去 src 的首地址。
const char *strstr(const char *src, const char* sub)
{
	if (src == nullptr || sub == nullptr)
		return src;
	const char *psrc, *psrcCopy = src;
	const char *psub;

	while (*src)
	{
		psrc = src;
		psub = sub;
		do
		{
			if (!*psub)
				return src;
		} while (*psub++ == *psrc++);
		src += 1;
	}
	return psrcCopy;
}