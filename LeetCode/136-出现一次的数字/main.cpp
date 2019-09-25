
#include <iostream>

int singleNumber(int* nums, int numsSize) {
	int result = 0;
	for (int i = 0; i < numsSize; ++i) {
		result ^= nums[i];
	}
	return result;
}

int main()
{
	int arr[10] = {1, 2, 2, 4, 6, 1, 5, 4, 6, 0};
	std::cout << singleNumber(arr, 10);
}


