#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>

using namespace std;

/*
给定一个无序的整数数组，找到其中最长上升子序列的长度。

示例:
输入: [10,9,2,5,3,7,101,18]
输出: 4
解释: 最长的上升子序列是 [2,3,7,101]，它的长度是 4。

说明:

可能会有多种最长上升子序列的组合，你只需要输出对应的长度即可。
你算法的时间复杂度应该为 O(n2) 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-increasing-subsequence
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
    /*
	提示：动态规划
	令 dp[i] 表示含 nums[i] 的最长上升子序列的长度，不是闭区间 [0, i]。
	dp[i] = max(dp[i], dp[j] + 1)	其中，j 属于 [0, i) 且 num[j] < num[i]
	*/
        if (nums.empty())
            return 0;
        vector<int> dp(nums.size(), 1);
        int max_length = 1;
        for (int i = 1; i < nums.size(); ++i)
            for (int j = i - 1; j >= 0; --j)
            {
                if (nums[j] < nums[i])
                {
                    dp[i] = max(dp[j] + 1, dp[i]);
                    max_length = max(dp[i], max_length);
                }
            }
        return max_length;
    }
};

int main(int argc, char** argv)
{
    ;
}