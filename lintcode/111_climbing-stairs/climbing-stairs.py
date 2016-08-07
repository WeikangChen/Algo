# coding:utf-8
'''
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/climbing-stairs
@Language: Python
@Datetime: 16-04-20 15:41
'''

class Solution:
    """
    @param n: An integer
    @return: An integer
    """
    def climbStairs(self, n):
        if n < 2:
            return 1
        f1, f2 = 1, 2
        for i in range(3, n+1):
            f1, f2 = f2, f1+f2
        return f2