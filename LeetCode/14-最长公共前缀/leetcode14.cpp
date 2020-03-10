#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
编写一个函数来查找字符串数组中的最长公共前缀。
如果不存在公共前缀，返回空字符串 ""。

示例 1:
输入: ["flower","flow","flight"]
输出: "fl"

示例 2:
输入: ["dog","racecar","car"]
输出: ""
解释: 输入不存在公共前缀。

说明:
所有输入只包含小写字母 a-z 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-common-prefix
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		/*
		方法一：
		将第一个字符串最为最长公共前缀 res，之后从第二个字符串 strs[2] 开始，
		逐个与 res 两两比较找出最长公共前缀，再用新的公共前缀更新 res 值。
		*/
		/*
		方法二：
		逐位比较
		*/
		;
	}
};

int main()
{
	string s = "abc";
	cout << s[3] << ' ' << s[4] << endl;

	getchar();
}
