void bubble(int *arr, int len)
{
	int t;
	for (int i = 0; i < len - 1; ++i)
		for (int j = 0; j < len - i - 1; ++j)
			if (arr[j] > arr[j + 1])
				t = arr[j], arr[j] = arr[j + 1], arr[j + 1] = t;
}