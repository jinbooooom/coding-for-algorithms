void* myMemcpy(void* memTo, void* memFrom, size_t size)
{
	if (memTo == nullptr || memFrom == nullptr)
		return nullptr;
	char *tmpFrom = (char *)memFrom;
	char *tmpTo = (char *)memTo;
	while (size -- > 0)
	// while (size--)
		*tmpTo++ = *tmpFrom++;
	return memTo;
}