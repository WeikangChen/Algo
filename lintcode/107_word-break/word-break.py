# coding:utf-8
'''
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/word-break
@Language: Python
@Datetime: 16-07-19 00:51
'''

class Solution:
    # @param s: A string s
    # @param dict: A dictionary of words dict
    def wordBreak(self, s, dict):
        n = len(s)
        dp = [True] + [False] * n
        len_max = max(map(len,dict)) if dict else 0
        for i in range(1, n+1):
            for j in range(i-1, max(0, i-len_max)-1, -1):
                if dp[j] and s[j:i] in dict:
                    dp[i] = True
                    break
                
        return dp[n]