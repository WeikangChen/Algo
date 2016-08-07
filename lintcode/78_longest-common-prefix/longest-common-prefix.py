# coding:utf-8
'''
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/longest-common-prefix
@Language: Python
@Datetime: 16-07-01 18:42
'''

class Solution:
    # @param strs: A list of strings
    # @return: The longest common prefix
    def longestCommonPrefix(self, strs):
        if not strs:
            return ""
        n = len(strs)
        l = len(strs[0])
        for s in strs:
            l = min(l, len(s))
        for i in range(l):
            c = strs[0][i]
            for j in range(1, n):
                if strs[j][i] != c:
                    return strs[j][0:i]
        return strs[0][0:l]
                