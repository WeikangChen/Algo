# coding:utf-8
'''
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/search-insert-position
@Language: Python
@Datetime: 16-05-01 02:51
'''

class Solution:
    """
    @param A : a list of integers
    @param target : an integer to be inserted
    @return : an integer
    """
    def searchInsert(self, A, target):
        l, r = 0, len(A)
        while l < r:
            m = (l + r) / 2
            if A[m] < target:
                l = m + 1
            else:
                r = m
        return l