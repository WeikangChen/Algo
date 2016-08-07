# coding:utf-8
'''
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/remove-duplicates-from-sorted-array
@Language: Python
@Datetime: 16-04-25 15:46
'''

class Solution:
    """
    @param A: a list of integers
    @return an integer
    """
    def removeDuplicates(self, A):
        j = 0
        for i in range(1, len(A)):
            if A[i] != A[j]:
                j += 1
                A[j] = A[i]
        return j+1