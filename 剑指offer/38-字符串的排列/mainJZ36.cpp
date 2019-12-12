#include <iostream>
#include <stdlib.h>
#include <assert.h>
#include <vector>
#include <string>
#include <memory>
#include <queue>
#include <algorithm>

using namespace std;
/*
"""
输入一个字符串,按字典序打印出该字符串中字符的所有排列。
例如输入字符串abc,则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。
输入一个字符串,长度不超过9(可能有字符重复),字符只包括大小写字母。
"""
提示：
对字符串 str = "abcd" 固定其索引为 fix（初始为0）的位置，将 a 与 fix 后面的位置的字符都作交换，可得到 "bacd"，"cbad"，"dbca"。
将这些字符串都添加到容器 res 中，再遍历每一个字符串，此时 fix++（为 1），
假设对字符串 "bacd" 操作，此时将索引为 fix = 1 的位置的字符，都与后面的字符交换，得到 "bcad", "bdca"。
*/
class Solution {
public:
	vector<string> Permutation(string str) {
		vector<string> res;
		if (str.empty())
			return res;
		res.push_back(str);
		int fix = 0;
		permutationCore(res, fix);
		sort(res.begin(), res.end());
		return res;
	}

	void permutationCore(vector<string>& res, int fix)
	{
		int resLength = res.size();
		int strLength = res[0].size();
		if (fix >= strLength - 1)
			return;
		for (int i = 0; i < resLength; ++i)  // 此处 resLength 不可用 res.size()，因为 res 会添加元素，造成 res.size() 动态变化
		{
			for (int j = fix + 1; j < strLength; ++j)
			{
				if (res[i][fix] != res[i][j])
					res.push_back(swap(res[i], fix, j)); // 值传递，不会改变 res[i]
			}
		}
		permutationCore(res, fix + 1);
	}

	string swap(string str, int i, int j)
	{
		char ch = str[i];
		str[i] = str[j];
		str[j] = ch;
		return str;
	}
};


int main(int argc, char* argv[]) {
	Solution s;
	string str("aab");
	vector<string> res;
	res = s.Permutation(str);
	cout << res.size() << endl;
	cout << "------------------------------\n";
	for (int i = 0; i < res.size(); ++i)
	{
		cout << res[i] << ' ';
	}
	getchar();
	//return 0;
}

