char *strcpy(char *strDst, const char *strSrc)  // 返回 char* 的目的是可以链式使用
{
	if (strDst == nullptr || strSrc == nullptr)
		return nullptr;

	char *strDstCopy = strDst;
	while ((*strDst++ = *strSrc++) != '\0');  // 比较之后再自增，把 '\0' 也复制过去了
	return strDstCopy;
}