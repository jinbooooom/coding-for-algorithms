#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
	bool canPartition(vector<int>& nums) {
		int s = sum(nums);
		if (s & 1)
			return false;
		s = s / 2; // 背包容量

		vector<int> dp(s + 1, 0);
		dp[0] = 1;

		for (int i = 0; i < nums.size(); ++i)
			for (int j = s; j >= nums[i]; --j)  // 01背包
			{
				dp[j] = dp[j - nums[i]] + dp[j];
				// leetcode 测试不通过，因为有大数相加 int 溢出，使用 canPartition2 稍微改一下就好了
			}
		return bool(dp[s]);
	}

	bool canPartition2(vector<int>& nums) {
		int s = sum(nums);
		if (s & 1)
			return false;
		s = s / 2; // 背包容量
		vector<int> dp(s + 1, false);
		dp[0] = true;

		for (int i = 0; i < nums.size(); ++i)
			for (int j = s; j >= nums[i]; --j)  // 01背包
			{
				dp[j] = dp[j - nums[i]] || dp[j];
			}
		return dp[s];
	}

	int sum(vector<int> nums)
	{
		int s = 0;
		for (int i = 0; i < nums.size(); ++i)
			s += nums[i];
		return s;
	}
};

int main()
{
	vector<int> nums{1, 5, 11, 5};
	Solution f;
	cout << f.canPartition(nums) << endl;
	cout << f.canPartition2(nums) << endl;

	getchar();
}