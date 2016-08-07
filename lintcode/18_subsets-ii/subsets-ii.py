# coding:utf-8
'''
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/subsets-ii
@Language: Python
@Datetime: 16-07-06 00:09
'''

class Solution:
    """
    @param S: A set of numbers.
    @return: A list of lists. All valid subsets.
    """
    def subsetsWithDup(self, S):
        n = len(S)
        one = []
        res = []
        S.sort()
        def dfs(p):
            res.append(one[:])
            for i in range(p, n):
                if i > p and S[i] == S[i-1]:
                    continue
                one.append(S[i])
                dfs(i+1)
                one.pop()
        dfs(0)
        return res