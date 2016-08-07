# coding:utf-8
'''
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/rotate-string
@Language: Python
@Datetime: 16-04-28 02:32
'''

class Solution:
    # @param s: a list of char
    # @param offset: an integer 
    # @return: nothing
    def rotateString(self, s, offset):
        if not s: return
        tmp = s[::-1]
        offset %= len(s)
        s[:] = tmp[offset-1::-1] + tmp[:offset-1:-1]