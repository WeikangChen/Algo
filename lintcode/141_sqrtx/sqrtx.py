# coding:utf-8
'''
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/sqrtx
@Language: Python
@Datetime: 16-04-27 03:39
'''

class Solution:
    """
    @param x: An integer
    @return: The sqrt of x
    """
    def sqrt(self, x):
        if x < 0:
            return -1
        if x < 2:
            return x
        xp = 1.0*x
        for i in range(20):
            xp = 0.5 * (xp + x / xp)
        return int(xp)