int partition(int *arr, int low, int high)
{
	int key = arr[low];  // 默认第一个数作为基准
	while (low < high) 
	{
		while (low < high && arr[high] >= key)
			high--;
		if (low < high)
			arr[low++] = arr[high];
		while (low < high && arr[low] <= key)
			low++;
		if (low < high)
			arr[high--] = arr[low];
	}
	arr[low] = key;
	return low;
}

void quick(int *arr, int start, int end)
{
	int pos;
	if (start < end)
	{
		pos = partition(arr, start, end);
		quick(arr, start, pos - 1);
		quick(arr, pos + 1, end);
	}
}