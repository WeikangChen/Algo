# coding:utf-8
'''
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/happy-number
@Language: Python
@Datetime: 16-04-22 14:56
'''

class Solution:
    # @param {int} n an integer
    # @return {boolean} true if this is a happy number or false
    def isHappy(self, n):
        for i in range(20):
            tmp, n = n, 0
            while tmp:
                n += (tmp % 10) ** 2
                tmp /= 10
        return n == 1