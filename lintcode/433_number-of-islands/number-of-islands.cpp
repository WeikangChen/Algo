/*
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/number-of-islands
@Language: C++
@Datetime: 16-05-14 19:09
*/

class Solution {
public:
    /**
     * @param grid a boolean 2D matrix
     * @return an integer
     */
    int numIslands(vector<vector<bool>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        const int m = grid.size();
        const int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int res = 0;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] && !visited[i][j]) {
                    dfs(i, j, m, n, grid, visited);
                    res++;
                }
            }
        return res;
    }
    void dfs(int i , int j, int m, int n,
            vector<vector<bool>>& grid,
            vector<vector<bool>>& visited) {
        if (i < 0 || i >= m) return;
        if (j < 0 || j >= n) return;
        if (!grid[i][j] || visited[i][j]) return;
        visited[i][j] = 1;
        dfs(i-1, j, m, n, grid, visited);
        dfs(i+1, j, m, n, grid, visited);
        dfs(i, j-1, m, n, grid, visited);
        dfs(i, j+1, m, n, grid, visited);
    }
};