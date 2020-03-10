/*
输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，所有的偶数位于数组的后半部分。
【假设保证奇数和奇数，偶数和偶数之间的相对位置不变，又如何做？】
*/

class Solution {
public:
    void reOrderArray(vector<int> &array) {
    // 方法一：类似冒泡排序，前面一个数为偶后面一个数为奇就调换位置，保证相对位置不变，时间复杂度为 O(nlogn)
        if (array.empty())
			return;
        int n = array.size();
        for (int i = 0; i < n - 1; ++i)
            for (int j = 0; j < n - 1 - i; ++j)
                if (!isOdd(array[j]) && isOdd(array[j + 1]))
                {
                    int t = array[j];
                    array[j] = array[j + 1];
                    array[j + 1] = t;
                }
	}

	void reOrderArray2(vector<int> &arr) {
	// 方法二：类似快排过程的 partition，但不保证相对位置不变，时间复杂度为 O(n)
		if (arr.empty())
			return;
		vector<int>::iterator p1 = arr.begin(), p2 = arr.end() - 1;
		while (p1 < p2)
		{
			while (isOdd(*p1) && p1 < p2)
				p1++;
			while (!isOdd(*p2) && p1 < p2)
				p2--;
			if (p1 < p2)
			{
				int tmp = *p1;
				*p1 = *p2;
				*p2 = tmp;
			}
		}
	}

	bool isOdd(int n)
	{
		return n & 1;
	}

	// 如果想保证奇数和奇数，偶数和偶数之间的相对位置不变，可以使用稳定性排序比如冒泡排序，只是需要改变比较大小的条件。
};