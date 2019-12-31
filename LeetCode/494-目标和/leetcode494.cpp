class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        if (nums.empty() || sum(nums) < S || (sum(nums) + S) % 2)
            return 0;
        int P = (sum(nums) + S) / 2;

        vector<int> dp(P + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < nums.size(); ++i)
            for (int j = P; j >= nums[i]; --j)
                dp[j] = dp[j - nums[i]] + dp[j];
        return dp[P];
    }

    int sum(vector<int> nums)
    {
        int s = 0;
        for (int i = 0; i < nums.size(); ++i)
            s += nums[i];
        return s;
    }
};