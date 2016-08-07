# coding:utf-8
'''
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/combinations
@Language: Python
@Datetime: 16-05-04 00:44
'''

class Solution:
    """    
    @param n: Given the range of numbers
    @param k: Given the numbers of combinations
    @return: All the combinations of k numbers out of 1..n
    """
    def combine(self, n, k):
        def util(p, n, k, one, res):
            if len(one) == k:
                res.append(one[:])
                return
            for i in range(p, n+1):
                one.append(i)
                util(i+1, n, k, one, res)
                one.pop()
        res = []
        util(1, n, k, [], res)
        return res