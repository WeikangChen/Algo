# coding:utf-8
'''
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/space-replacement
@Language: Python
@Datetime: 16-05-05 03:33
'''

class Solution:
    # @param {char[]} string: An array of Char
    # @param {int} length: The true length of the string
    # @return {int} The true length of new string
    def replaceBlank(self, string, length):
        if not string:
            return 0
        string[:] = ''.join(map(lambda x: '%20' if x == ' ' else x , string))
        return len(string)