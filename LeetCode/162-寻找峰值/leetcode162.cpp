#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>

using namespace std;

/*
https://leetcode-cn.com/problems/find-peak-element

峰值元素是指其值大于左右相邻值的元素。

给定一个输入数组 nums，其中 nums[i] ≠ nums[i+1]，找到峰值元素并返回其索引。
数组可能包含多个峰值，在这种情况下，返回任何一个峰值所在位置即可。
你可以假设 nums[-1] = nums[n] = -∞。

示例 1:
输入: nums = [1,2,3,1]
输出: 2
解释: 3 是峰值元素，你的函数应该返回其索引 2。

示例 2:
输入: nums = [1,2,1,3,5,6,4]
输出: 1 或 5
解释: 你的函数可以返回索引 1，其峰值元素为 2；
或者返回索引 5， 其峰值元素为 6。

*/

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
    /*
    首先要注意题目条件，在题目描述中出现了 nums[-1] = nums[n] = -∞，这就代表着 只要数组中存在一个元素比相邻元素大，那么沿着它一定可以找到一个峰值
    根据上述结论，我们就可以使用二分查找找到峰值。
    只需要找到任意一个峰值即可。
    设置左右指针分别指向第一个和最后一个元素，根据左右指针计算中间位置 m，并比较 m 与 m + 1 的值，
    如果 m 较大，则左侧存在峰值，right = m，如果 m + 1 较大，则右侧存在峰值，left = m + 1

    通俗的说法是：
    由于边界是负无穷，只要往上坡方向走，即使走到边界，一定能找到山峰。总的一句话，往递增的方向上，二分，一定能找到，往递减的方向只是可能找到，也许没有。

    作者：guanpengchn
    链接：https://leetcode-cn.com/problems/find-peak-element/solution/hua-jie-suan-fa-162-xun-zhao-feng-zhi-by-guanpengc/
    来源：力扣（LeetCode）
    著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
  
    */
        int left = 0, right = nums.size() - 1;
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums[mid + 1])
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }
};



