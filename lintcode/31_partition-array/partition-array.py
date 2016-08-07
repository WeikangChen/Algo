# coding:utf-8
'''
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/partition-array
@Language: Python
@Datetime: 16-07-01 20:06
'''

class Solution:
    """
    @param nums: The integer array you should partition
    @param k: As description
    @return: The index after partition
    """
    def partitionArray(self, nums, k):
        p = 0
        for i in range(len(nums)):
            if nums[i] < k:
                nums[p], nums[i] = nums[i], nums[p]
                p += 1
        return p
