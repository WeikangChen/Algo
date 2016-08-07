# coding:utf-8
'''
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/length-of-last-word
@Language: Python
@Datetime: 16-04-24 18:07
'''

class Solution:
    # @param {string} s A string
    # @return {int} the length of last word
    def lengthOfLastWord(self, s):
        lst = s.split()
        return 0 if not lst else len(lst[-1])