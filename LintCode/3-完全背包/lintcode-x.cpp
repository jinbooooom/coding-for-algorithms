#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
给定 n 种尺寸为 A[i] 且值为 V[i] 的物品（每件物品都有无限数量）和尺寸为 m 的背包。
装入背包的物品总价值最大是多大?

例：
给出 4 个尺寸为 [2,3,5,7] 且值为 [1,5,2,4] 的物品，
以及尺寸为 10 的背包。
背包内物品最大值为 15，即选三个价值为 5 的物品。
*/

int backPackIII(vector<int> A, vector<int> V, int m)
{
	/*
	dp[i][j]：前 i 个物品放入容量为 j 的背包的最大价值；
	dp[i][j-A[i]] + V[i]：放入第 i个物品时，不管上一次放没放入过该物品；
	dp[i-1][j]：不放入第 i 个物品时的价值；

	在遇到第 i 个物品时，需要考虑该物品是放入还是不放入
	状态转移方程为：
	dp[i][j] = max(dp[i][j-A[i]] + V[i], dp[i-1][j])

	可简化成一维，令 dp[j] 为容量 j 的背包，装起物品的最大重量。
	dp[j] = max(dp[j-A[i]] + V[i], dp[j])
	*/
	if (m <= 0 || A.empty() || V.empty())
		return 0;
	vector<int> dp(m + 1, 0);
	for (int i = 0; i < A.size(); ++i)
		for (int j = A[i]; j <= m; ++j) // 完全背包，所以以容量的 for 循环 j 是从小到大递增
			dp[j] = max(dp[j - A[i]] + V[i], dp[j]);
	return dp[m];
}

int main()
{
	vector<int> A{2, 3, 5, 7};
	vector<int> V{1, 5, 2, 4};
	int m = 10;
	cout << backPackIII(A, V, m) << endl;

	getchar();
}