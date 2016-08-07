# coding:utf-8
'''
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/reverse-words-in-a-string
@Language: Python
@Datetime: 16-04-25 01:12
'''

class Solution:
    # @param s : A string
    # @return : A string
    def reverseWords(self, s):
        list = s.split()
        return " ".join(reversed(list))