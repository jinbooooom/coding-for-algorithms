void insert(int *arr, int len)
{
	int i, j, t;
	for (i = 1; i < len; ++i)  // 从第二个数开始（索引1），一共 len - 1 轮
	{
		t = arr[i];
		for (j = i - 1; j >= 0 && t < arr[j]; --j)
			arr[j + 1] = arr[j];
		arr[j + 1] = t;
	}
}