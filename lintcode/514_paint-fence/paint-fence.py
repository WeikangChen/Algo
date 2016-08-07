# coding:utf-8
'''
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/paint-fence
@Language: Python
@Datetime: 16-05-03 01:38
'''

class Solution:
    # @param {int} n non-negative integer, n posts
    # @param {int} k non-negative integer, k colors
    # @return {int} an integer, the total number of ways
    def numWays(self, n, k):
        if n == 1: return k
        if k == 1: return 1 if n < 3 else 0

        dp1, dp2 = k, k*k
        for i in range(2, n):
            dp1, dp2 = dp2, (k-1) * (dp2 + dp1)
            
        return dp2
        