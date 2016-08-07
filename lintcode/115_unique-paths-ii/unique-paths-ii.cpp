/*
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/unique-paths-ii
@Language: C++
@Datetime: 16-07-12 23:54
*/

class Solution {
public:
    /**
     * @param obstacleGrid: A list of lists of integers
     * @return: An integer
     */ 
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        if (obstacleGrid.empty() || obstacleGrid[0].empty()) return 0;
        const int m = obstacleGrid.size();
        const int n = obstacleGrid[0].size();
        vector<int> dp(n, 0);
        dp[0] = 1;
        
        for (int i = 0; i < m; i ++) {
            if (obstacleGrid[i][0]) dp[0] = 0;
            for (int j = 1; j < n; j++) {
                if(obstacleGrid[i][j]) 
                    dp[j] = 0;
                else
                    dp[j] += dp[j-1];
            }
        }
        return dp[n-1];
    }
};