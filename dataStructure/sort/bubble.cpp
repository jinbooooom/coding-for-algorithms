void bubble(int *arr, int len)
{
	int t;
	for (int i = 0; i < len - 1; ++i)  // 一共有 len - 1 轮
		for (int j = 0; j < len - i - 1; ++j)  // 每轮有 len - i - 1 次比较
			if (arr[j] > arr[j + 1])  // 前面数字大于后面数字，就交换
				t = arr[j], arr[j] = arr[j + 1], arr[j + 1] = t;
}