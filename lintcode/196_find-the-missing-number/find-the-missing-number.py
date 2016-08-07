# coding:utf-8
'''
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/find-the-missing-number
@Language: Python
@Datetime: 16-04-25 01:20
'''

class Solution:
    # @param nums: a list of integers
    # @return: an integer
    def findMissing(self, nums):
        n = len(nums)
        return n * (n+1) / 2 - sum(nums)
