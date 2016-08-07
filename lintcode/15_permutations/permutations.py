# coding:utf-8
'''
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/permutations
@Language: Python
@Datetime: 16-05-03 23:47
'''

class Solution:
    """
    @param nums: A list of Integers.
    @return: A list of permutations.
    """
    def permute(self, nums):
        def perm(nums, p, n, res):
            if p == n:
                res.append(nums[:])
                return
            for i in range(p, n):
                nums[p], nums[i] = nums[i], nums[p] 
                perm(nums, p+1, n, res)
                nums[p], nums[i] = nums[i], nums[p]
        if not nums:
            return []
        res = []
        perm(nums, 0, len(nums), res)
        return res
