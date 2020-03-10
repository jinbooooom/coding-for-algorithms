#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>

using namespace std;

/*
https://leetcode-cn.com/problems/3sum

给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？
找出所有满足条件且不重复的三元组。

注意：答案中不可以包含重复的三元组。
例如, 给定数组 nums = [-1, 0, 1, 2, -1, -4]，

满足要求的三元组集合为：
[
[-1, 0, 1],
[-1, -1, 2]
]
*/


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
    /*
	算法流程：
    对数组进行排序。
    遍历排序后的数组：
        若 nums[i] > 0：因为已经排序好，所以后面不可能有三个数加和等于 0，直接返回结果。
        对于重复元素：跳过，避免出现重复解
        令左指针 pl = i+1，右指针 pr = n−1，当 pl < pr 时，执行循环：
            若 num[i] + nums[pl] + nums[pr] 大于 0，说明 nums[pr] 太大，pr 左移;
            若 num[i] + nums[pl] + nums[pr] 小于 0，说明 nums[pl] 太小，pl 右移
	*/
        int n = nums.size();
        vector<vector<int> > res;
        if (nums.empty() || n < 3)
            return res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; ++i)
        {
            if (nums[i] > 0)
                return res;
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int pl = i + 1;
            int pr = n - 1;
            while (pl < pr)
            {
                if (nums[i] + nums[pl] + nums[pr] == 0)
                {
                    res.push_back({nums[i], nums[pl], nums[pr]});
                    while (pl < pr && nums[pl] == nums[pl + 1])
                        ++pl;
                    while (pl < pr && nums[pr] == nums[pr - 1])
                        --pr;
                    ++pl;
                    --pr;
                }
                else if (nums[i] + nums[pl] + nums[pr] > 0)
                    --pr;
                else
                    ++pl;
            }
        }
        return res;
    }
};
