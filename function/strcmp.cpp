int myStrcmp(const char *src, const char *dst)
{
	if (src != nullptr && dst == nullptr)
		return *src;
	else if (src == nullptr && dst == nullptr)
		return 0;
	else if (src == nullptr && dst != nullptr)
		return -*dst;

	while (*src && *dst && *src == *dst)
	{
		src++;
		dst++;
	}
	return *src - *dst;
}