# coding:utf-8
'''
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/remove-element
@Language: Python
@Datetime: 16-04-25 15:37
'''

class Solution:
    """
    @param A: A list of integers
    @param elem: An integer
    @return: The new length after remove
    """
    def removeElement(self, A, elem):
        j = 0
        for i in range(len(A)):
            if A[i] != elem:
                A[j], A[i] = A[i], A[j]
                j += 1
        return j
            