# coding:utf-8
'''
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/reverse-integer
@Language: Python
@Datetime: 16-04-26 13:15
'''

class Solution:
    # @param {int} n the integer to be reversed
    # @return {int} the reversed integer
    def reverseInteger(self, n):
        sig = 1
        if n < 0:
            n = -n
            sig = -1
        res = 0
        while n:
            res = res * 10 + n % 10
            n /= 10
        
        if res > 2147483647:
            return 0
        res *= sig
        return res