/*
https://leetcode-cn.com/problems/number-of-islands/solution/number-of-islands-shen-du-you-xian-bian-li-dfs-or-/
*/

class Solution {
private:
    vector<vector<int> > directions {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

public:
    int numIslands(vector<vector<char>>& grid) {
    // 深度优先搜索 dfs
        if (grid.empty())
            return 0;
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        vector<vector<bool> > marked(m, vector<bool>(n, false));
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (!marked[i][j] && grid[i][j] == '1')
                {
                    count++;
                    dfs(grid, i, j, m, n, marked);
                }
        return count;
    }

    void dfs(vector<vector<char> >& grid, int i, int j, int m, int n, vector<vector<bool> >& marked)
    {
        marked[i][j] = true;
        for (int direct = 0; direct < directions.size(); ++direct)
        {
            int new_i = i + directions[direct][0];
            int new_j = j + directions[direct][1];
            if (new_i >= 0 && new_i < m && new_j >= 0 && new_j < n && !marked[new_i][new_j] && grid[new_i][new_j] == '1')
                dfs(grid, new_i, new_j, m, n, marked);
        }
    }
};

