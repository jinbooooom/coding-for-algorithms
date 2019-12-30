class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.empty())
            return 0;
        int m = grid.size();
        int n = grid[0].size();
        int dp[m][n] = {0};
        // 处理边界
        dp[0][0] = grid[0][0];
        for (int i = 1; i < m; ++i)  // 处理索引为 0 的列
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        for (int j = 1; j < n; ++j) // 处理索引为 0 的行
            dp[0][j] = dp[0][j - 1] + grid[0][j];
        for (int i = 1; i < m; ++i)
            for (int j = 1; j < n; ++j)
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
        return dp[m - 1][n - 1];
    }
};