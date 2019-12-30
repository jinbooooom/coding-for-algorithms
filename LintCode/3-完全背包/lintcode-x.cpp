#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int backPackIII(vector<int> A, vector<int>V, int m)
{
	if (m <= 0 || A.empty() || V.empty())
		return 0;
	vector<int> dp(m + 1, 0);
	for (int i = 0; i < A.size(); ++i)
		for (int j = A[i]; j <= m; ++j)
			dp[j] = max(dp[j - A[i]] + V[i], dp[j]);
	return dp[m];
}

int main()
{
	vector<int> A{ 2, 3, 5, 7 };
	vector<int> V{ 1, 5, 2, 4 };
	int m = 10;
	cout << backPackIII(A, V, m) << endl;

	getchar();
}