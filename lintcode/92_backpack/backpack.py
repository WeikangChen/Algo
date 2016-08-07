# coding:utf-8
'''
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/backpack
@Language: Python
@Datetime: 16-07-19 00:18
'''

class Solution:
    # @param m: An integer m denotes the size of a backpack
    # @param A: Given n items with size A[i]
    # @return: The maximum size
    def backPack(self, m, A):
        dp = [True] + [False] * m
        
        for a in A:
            for i in range(m, a-1, -1):
                dp[i] = dp[i] or dp[i-a]
                
        for i in range(m,-1,-1):
            if dp[i]:
                return i