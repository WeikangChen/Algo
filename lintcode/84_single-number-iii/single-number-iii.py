# coding:utf-8
'''
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/single-number-iii
@Language: Python
@Datetime: 16-07-01 00:04
'''

class Solution:
    """
    @param A : An integer array
    @return : Two integer
    """
    def singleNumberIII(self, A):
        n = 0;
        for a in A:
            n ^= a
        t = n & (-n)
        res1, res2 = 0, 0
        for a in A:
            if t & a:
                res1 ^= a
            else:
                res2 ^= a
        return res1, res2