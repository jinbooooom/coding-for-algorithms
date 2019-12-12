void select(int *arr, int len)
{
	int i, j, k, t;
	for (i = 0; i < len - 1; ++i)
	{
		k = i;
		for (j = i + 1; j < len; j++)
			if (arr[j] < arr[k])
				k = j;
		if (k != i)
			t = arr[i], arr[i] = arr[k], arr[k] = t;
	}
}