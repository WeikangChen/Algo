# coding:utf-8
'''
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/longest-words
@Language: Python
@Datetime: 16-04-25 01:11
'''

class Solution:
    # @param dictionary: a list of strings
    # @return: a list of strings
    def longestWords(self, dictionary):
        longest = 0
        res = []
        for word in dictionary:
            longest = max(longest, len(word))
        for word in dictionary:
            if len(word) == longest:
                res.append(word)
        return res