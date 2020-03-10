/*
https://leetcode-cn.com/problems/missing-number
给定一个包含 0, 1, 2, ..., n 中 n 个数的序列，找出 0 .. n 中没有出现在序列中的那个数。

示例 1:
输入: [3,0,1]
输出: 2

示例 2:
输入: [9,6,4,2,3,5,7,0,1]
输出: 8
*/

#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>

using namespace std;

class Solution {
public:
	int missingNumber(vector<int>& nums) {
	/*
	基本方法如：排序，建立哈希表，略去

	方法一：使用异或运算，使时间复杂度为 O(n)，空间复杂度 O(1)

	包含数字 0~n 的序列按理是要用 n+1 长度的数组存储，但该序列缺少了一个数字 x，x 属于区间 [0, n]，
	由于相同的数字异或为 0，则将索引 0~n 与序列依次异或，得到的最终结果就是缺失的数字。

	例如 nums = [3, 0, 1]，若不缺少 2，则用长度为 4 的数组来存储，该数组索引为 0~3，
	x = 3 ^ 0 ^ 1 ^ 0 ^ 1 ^ 2 ^ 3
	  = (0 ^ 0) ^ (1 ^ 1) ^ 2 ^ (3 ^ 3)
	  = 2

	方法二：数学
	区间 [0, n] 上的数字之和为 s1, nums 是区间 [0, n] 中缺少一个数字 x 组成的数组，设对 nums 求和为 s2,
	则 x = s1 - s2
	*/


	}
};

