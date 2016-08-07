# coding:utf-8
'''
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/trailing-zeros
@Language: Python
@Datetime: 16-04-24 21:33
'''

class Solution:
    # @param n a integer
    # @return ans a integer
    def trailingZeros(self, n):
        cnt = 0
        while n:
            n /= 5
            cnt += n
        return cnt