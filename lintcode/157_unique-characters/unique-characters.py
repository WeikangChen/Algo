# coding:utf-8
'''
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/unique-characters
@Language: Python
@Datetime: 16-04-24 21:30
'''

class Solution:
    # @param s: a string
    # @return: a boolean
    def isUnique(self, str):
        return len(set(str)) == len(str)