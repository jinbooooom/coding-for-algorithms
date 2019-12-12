int myStrlen(const char *str)
{
	assert(str != nullptr);			// 需要头文件 #include <assert.h>
	//if (str == nullptr) return 0;
	const char *p = str;
	while (*str++ != '\0');
	return str - p - 1;
}