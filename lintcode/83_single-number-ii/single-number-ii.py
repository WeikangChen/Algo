# coding:utf-8
'''
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/single-number-ii
@Language: Python
@Datetime: 16-07-01 00:31
'''

class Solution:
    """
	@param A : An integer array
	@return : An integer
    """
    def singleNumberII(self, A):
        res = [0] * 32
        x = 0
        for i in range(32):
            for a in A:
                if a & (1 << i):
                    res[i] += 1
            if res[i] % 3:
                x |= (1 << i)
        return x
        