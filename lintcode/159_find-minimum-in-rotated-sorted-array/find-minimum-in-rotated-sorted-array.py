# coding:utf-8
'''
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/find-minimum-in-rotated-sorted-array
@Language: Python
@Datetime: 16-05-05 03:25
'''

class Solution:
    # @param num: a rotated sorted array
    # @return: the minimum number in the array
    def findMin(self, num):
        l, r = 0, len(num)-1
        while l < r:
            if num[l] < num[r]:
                break
            m = (l + r) / 2
            if num[m] > num[r]:
                l = m + 1
            else:
                r = m
        return num[l]