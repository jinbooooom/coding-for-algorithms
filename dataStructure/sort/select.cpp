void select(int *arr, int len)
{
	int i, j, k, t;
	for (i = 0; i < len - 1; ++i)
	{
		k = i;
		for (j = i + 1; j < len; j++)
			if (arr[j] < arr[k])	// 把比 arr[k] 更小的值的索引赋给 k
				k = j;
		if (k != i)
			t = arr[i], arr[i] = arr[k], arr[k] = t;
	}
}