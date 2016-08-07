# coding:utf-8
'''
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/next-permutation
@Language: Python
@Datetime: 16-07-01 18:08
'''

class Solution:
    # @param num :  a list of integer
    # @return : a list of integer
    def nextPermutation(self, num):
        l = len(num)
        i = j = l - 1
        while i and num[i-1] >= num[i]:
            i -= 1
        if i == 0:
            return list(reversed(num))
        while num[i-1] >= num[j]:
            j -= 1
        
        num[i-1], num[j] = num[j], num[i-1]
        return num[0:i] + num[l-1:i-1:-1]
