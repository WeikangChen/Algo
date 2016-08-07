# coding:utf-8
'''
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/jump-game
@Language: Python
@Datetime: 16-07-11 23:21
'''

class Solution:
    # @param A, a list of integers
    # @return a boolean
    def canJump(self, A):
        n = len(A)
        pos = 0
        while pos < n-1:
            max_jump = 0
            for i in range(A[pos]+1):
                if pos+i < n:
                    max_jump = max(max_jump, A[pos+i])
            if max_jump == 0:
                return False
            pos += max_jump
        return True