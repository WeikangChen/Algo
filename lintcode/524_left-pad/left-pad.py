# coding:utf-8
'''
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/left-pad
@Language: Python
@Datetime: 16-04-25 20:36
'''

class StringUtils:
    # @param {string} originalStr the string we want to append to
    # @param {int} size the target length of the string
    # @param {string} padChar the character to pad to the left side of the string
    # @return {string} a string
    @classmethod
    def leftPad(self, originalStr, size, padChar=' '):
        return padChar * (size - len(originalStr)) + originalStr
        