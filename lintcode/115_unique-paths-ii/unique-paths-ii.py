# coding:utf-8
'''
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/unique-paths-ii
@Language: Python
@Datetime: 16-07-13 00:04
'''

class Solution:
    """
    @param obstacleGrid: An list of lists of integers
    @return: An integer
    """
    def uniquePathsWithObstacles(self, obstacleGrid):
        if not obstacleGrid or not obstacleGrid[0]:
            return 0
        m = len(obstacleGrid)
        n = len(obstacleGrid[0])
        
        dp = [0] * n
        dp[0] = 1;
        for i in range(m):
            if obstacleGrid[i][0]:
                dp[0] = 0
            for j in range(1, n):
                if obstacleGrid[i][j]:
                    dp[j] = 0
                else:
                    dp[j] += dp[j-1];
        return dp[n-1]
