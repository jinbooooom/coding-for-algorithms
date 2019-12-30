class Solution {
public:
    /**
     * @param nums: an integer array and all positive numbers, no duplicates
     * @param target: An integer
     * @return: An integer
     */
    int backPackIV(vector<int> &nums, int target) {
        // write your code here
        if (target <= 0 || nums.empty())
            return 0;
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < nums.size(); ++i)
            for (int j = nums[i]; j <= target; ++j)
                dp[j] = dp[j - nums[i]] + dp[j];
        return dp[target];
    }
};