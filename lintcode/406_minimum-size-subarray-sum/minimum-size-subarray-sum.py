# coding:utf-8
'''
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/minimum-size-subarray-sum
@Language: Python
@Datetime: 16-04-22 19:39
'''

class Solution:
    # @param nums: a list of integers
    # @param s: an integer
    # @return: an integer representing the minimum size of subarray
    def minimumSize(self, nums, s):
        n = len(nums)
        min_win = n + 1
        sum = j = 0
        for i in range(n):
            sum += nums[i]
            if sum >= s:
                while sum >= s:
                    sum -= nums[j]
                    j += 1
                min_win = min(min_win, i - j + 2)
        return min_win if min_win < n + 1 else -1