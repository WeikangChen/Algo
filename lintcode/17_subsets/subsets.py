# coding:utf-8
'''
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/subsets
@Language: Python
@Datetime: 16-07-06 03:12
'''

class Solution:
    """
    @param S: The set of numbers.
    @return: A list of lists. See example.
    """
    def subsets(self, S):
        res = [[]]
        for s in sorted(S):
            res = res + [one+[s] for one in res]
        return res