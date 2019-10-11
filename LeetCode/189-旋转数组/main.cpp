class Solution {
public:
	void rotate(vector<int>& nums, int k) {
		int size = nums.size();
		if (size < 1)
			return;
		k %= size;
		int left = 0, right = size - 1;
		reserve(nums, left, right);
		reserve(nums, left, k - 1);
		reserve(nums, k, right);
	}

	void swap(int& a, int& b) {
		//不用其他变量实现两个数的交换：
		//https://blog.csdn.net/M771310443/article/details/21245675
		// 两个相同的数与一个不同的数异或，就等于这个不同的数
		a = a ^ b;
		b = a ^ b;
		a = a ^ b;
	}

	void reserve(vector<int>& nums, int left, int right) {
		while (right > left) {
			swap(nums[right], nums[left]);
			left++, right--;
		}
	}
};
