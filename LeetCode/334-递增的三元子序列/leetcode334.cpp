/*
链接：https://leetcode-cn.com/problems/increasing-triplet-subsequence
给定一个未排序的数组，判断这个数组中是否存在长度为 3 的递增子序列。
数学表达式如下:
    如果存在这样的 i, j, k,  且满足 0 ≤ i < j < k ≤ n-1，
    使得 arr[i] < arr[j] < arr[k] ，返回 true ; 否则返回 false 。

说明: 要求算法的时间复杂度为 O(n)，空间复杂度为 O(1) 。

示例 1:
输入: [1,2,3,4,5]
输出: true

示例 2:
输入: [5,4,3,2,1]
输出: false

*/


class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
    /*
    方法一：动态规划，时间复杂度：O(n^2)，空间复杂度：O(n)。
    dp[i]：前 i 个元素中，比 nums[i] 小的元素有多少个
    */
        int size = nums.size();
        vector<int> dp(size, 1);
        for (int i = 0; i < size; ++i) 
        {
            for (int j = 0; j < i; ++j) 
            {
                if (nums[j] < nums[i]) 
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
                if (dp[i] >= 3)
                    return true;
            }
        }
        return false;
    }

    bool increasingTriplet2(vector<int>& nums) {
    /*
    找到两个较小的数 m1, m2，再找到一个数，比这两个较小的数大，说明有递增的三元子序列
    时间复杂度：O(n)，空间复杂度：O(1)
    */
        int m1 = INT_MAX, m2 = INT_MAX;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (m1 >= nums[i])
                m1 = nums[i];  // m1 是目前遍历的部分中最小的数
            else if (m2 >= nums[i]) // m1 < nums[i] <= m2
                m2 = nums[i];  // m2 是目前遍历的部分中比 m1 大的最小的数
            else
                return true;  // 找到了一个数比 m1，m2 都大，说明有递增的三元子序列
        }
        return false;
    }
};