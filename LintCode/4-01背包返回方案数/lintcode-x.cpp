#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
	int backPackIV(vector<int>& nums, int target) {
		if (target <= 0 || nums.empty())
			return 0;
		vector<int> dp(target + 1, 0);
		dp[0] = 1;
		for (int i = 0; i < nums.size(); ++i)
			for (int j = target; j >= nums[i]; --j)
				dp[j] = dp[j - nums[i]] + dp[j];
		return dp[target];
	}
};

int main()
{
	vector<int> nums{7, 3, 6, 2};
	int target = 9;
	Solution f;
	cout << f.backPackIV(nums, target) << endl;

	getchar();
}