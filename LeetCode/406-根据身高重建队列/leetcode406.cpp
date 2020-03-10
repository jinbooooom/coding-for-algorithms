/*
https://leetcode-cn.com/problems/queue-reconstruction-by-height

假设有打乱顺序的一群人站成一个队列。 每个人由一个整数对(h, k)表示，
其中 h 是这个人的身高，k是排在这个人前面且身高大于或等于h的人数。
编写一个算法来重建这个队列。

注意：
总人数少于1100人。

示例：
输入:
[[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]

输出:
[[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]
*/

class Solution
{
public:
	vector<vector<int>> reconstructQueue(vector<vector<int>>& people)
	{
	/*
	思路：
	按第一个元素（身高）降序排序，第二个元素（人数）升序排序。
	再将第二个元素的位置将元素插入到数组中，画个图就全部明白了。
	*/
		// 身高降序排列，人数升序排列
		sort(people.begin(), people.end(), cmp);
		vector<vector<int> > res;
		for (int i = 0; i < people.size(); i++)
			res.insert(res.begin() + people[i][1], people[i]);
		return res;
	}

	static bool cmp(const vector<int>& a, const vector<int>& b) // 自定义的比较规则 cmp 得是静态成员函数
	// a, b 均是一个数对，按第一个元素（身高）降序排序，第二个元素（人数）升序排序
	{
		if (a[0] > b[0])
			return true;
		if (a[0] == b[0] && a[1] < b[1])
			return true;
		return false;
	}
};