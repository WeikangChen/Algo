# coding:utf-8
'''
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/permutations-ii
@Language: Python
@Datetime: 16-07-07 23:17
'''

class Solution:
    """
    @param nums: A list of integers.
    @return: A list of unique permutations.
    """
    def permuteUnique(self, nums):
        n = len(nums)
        res = []
        def helper(p):
            if p == -1:
                res.append(nums[:])
            else:
                for i in range(p, n):
                    if i > p and nums[i] == nums[p]:
                        break
                    nums[i], nums[p] = nums[p], nums[i]
                    helper(p-1)
                    nums[i], nums[p] = nums[p], nums[i]
        helper(n-1)
        return res