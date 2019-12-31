#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
	int findMaxForm(vector<string>& strs, int m, int n) {
		vector<vector<int> > dp(m + 1, vector<int>(n + 1, 0));
		for (int i = 0; i < int(strs.size()); ++i)
		{
			int s0 = count(strs[i], '0');
			int s1 = count(strs[i], '1');
			for (int j = m; j >= s0; --j)
				for (int k = n; k >= s1; --k)
					dp[j][k] = max(dp[j][k], 1 + dp[j - s0][k - s1]);
		}
		return dp[m][n];
	}

	int count(string str, char ch)
	{
		int cnt = 0;
		for (int i = 0; i < int(str.size()); ++i)
			if (str[i] == ch)
				cnt++;
		return cnt;
	}
};

int main()
{

	vector<string> strs{ "10", "0", "1" };
	int m = 1;
	int n = 1;
	Solution f;
	cout << f.findMaxForm(strs, m, n) << endl;

	getchar();
}