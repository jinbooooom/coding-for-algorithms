/*
https://leetcode-cn.com/problems/two-sum

给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那两个整数，并返回他们的数组下标。
你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。

示例:
给定 nums = [2, 7, 11, 15], target = 9

因为 nums[0] + nums[1] = 2 + 7 = 9
所以返回 [0, 1]
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int size = nums.size();
        map<int, int> index;
        vector<int> id(2);
        for (int i = 0; i < size; ++i)
        {
            index[nums[i]] = i;
        }
        for (int i = 0; i < size; ++i)
        {
            if (index.count(target - nums[i]) && index[target - nums[i]] != i)
            {
                id[0] = i;
                id[1] = index[target - nums[i]];
                return id;
            }
        }
        return id;
    }
};