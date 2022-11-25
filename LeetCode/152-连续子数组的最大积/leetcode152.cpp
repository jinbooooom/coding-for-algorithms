/*
https://leetcode-cn.com/problems/maximum-product-subarray
给定一个整数数组 nums ，找出一个序列中乘积最大的连续子序列（该序列至少包含一个数）。

示例 1:
输入: [2,3,-2,4]
输出: 6
解释: 子数组 [2,3] 有最大乘积 6。

示例 2:
输入: [-2,0,-1]
输出: 0
解释: 结果不能为 2, 因为 [-2,-1] 不是子数组。
*/

class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        /**
        对于乘法，需要注意，负数乘以负数，会变成正数，所以处理起来，跟连续子数组的最大和不太一样。
        dp_max[i]：以索引为 i 的数结尾的连续子数组的最大积;
        dp_min[i]：以索引为 i 的数结尾的连续子数组的最小积;

        状态转移方程为：
        dp_min[i] = min(nums[i], min(dp_min[i - 1] * nums[i], dp_max[i - 1] * nums[i]));
        dp_max[i] = max(nums[i], max(dp_min[i - 1] * nums[i], dp_max[i - 1] * nums[i]));
        */
        if (nums.empty())
            return 0;
        if (nums.size() == 1)
            return nums[0];
        int m = nums[0];
        vector<int> dp_min(nums.size(), 1);
        vector<int> dp_max(nums.size(), 1);
        dp_min[0] = dp_max[0] = nums[0];
        for (int i = 1; i < nums.size(); ++i)
        {
            dp_min[i] = min(nums[i], min(dp_min[i - 1] * nums[i], dp_max[i - 1] * nums[i]));
            dp_max[i] = max(nums[i], max(dp_min[i - 1] * nums[i], dp_max[i - 1] * nums[i]));
            m = max(m, dp_max[i]);
        }
        return m;
    }
};