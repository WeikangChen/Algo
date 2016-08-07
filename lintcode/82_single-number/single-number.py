# coding:utf-8
'''
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/single-number
@Language: Python
@Datetime: 16-05-01 02:56
'''

class Solution:
    """
    @param A : an integer array
    @return : a integer
    """
    def singleNumber(self, A):
        return reduce(lambda x, y: x ^ y, A, 0)