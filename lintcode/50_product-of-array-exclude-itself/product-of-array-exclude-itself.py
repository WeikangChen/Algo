# coding:utf-8
'''
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/product-of-array-exclude-itself
@Language: Python
@Datetime: 16-07-02 22:01
'''

class Solution:
    """
    @param A: Given an integers array A
    @return: An integer array B and B[i]= A[0] * ... * A[i-1] * A[i+1] * ... * A[n-1]
    """
    def productExcludeItself(self, A):
        n = len(A)
        l = [1] * (n+1)
        r = [1] * (n+1)
        for i in range(1, n+1):
            l[i] = l[i-1] * A[i-1]
            r[n-i] = r[n-i+1] * A[n-i]
        res = [0] * n
        for i in range(n):
            res[i] = l[i] * r[i+1];
        return res
            
        