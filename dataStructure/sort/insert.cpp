void insert(int *arr, int len)
{
	int i, j, t;
	for (i = 1; i < len; ++i)
	{
		t = arr[i];
		for (j = i - 1; j >= 0 && t < arr[j]; --j)
			arr[j + 1] = arr[j];
		arr[j + 1] = t;
	}
}