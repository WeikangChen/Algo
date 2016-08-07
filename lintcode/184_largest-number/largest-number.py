# coding:utf-8
'''
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/largest-number
@Language: Python
@Datetime: 16-07-09 14:30
'''

class Solution:	
    #@param num: A list of non negative integers
    #@return: A string
    def largestNumber(self, num):
        def cmp(x, y):
            s1 = str(x)+str(y)
            s2 = str(y)+str(x)
            return 1 if int(s2) - int(s1) > 0 else -1
        n = sorted(num, cmp)
        return  "0" if all([i == 0 for i in n]) else "".join(map(str, n))