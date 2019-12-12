char *myStrcat(char *dst, char *src)
{
	assert(src != nullptr && dst != nullptr);	// src 与 dst 非空
	assert(dst != src);							// 不能让一个字符串与其本身连接

	char *dstCopy = dst;
	while (*dst)
		dst++;
	while (*dst++ = *src++);
	return dstCopy;
}