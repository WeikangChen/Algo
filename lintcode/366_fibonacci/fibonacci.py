# coding:utf-8
'''
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/fibonacci
@Language: Python
@Datetime: 16-04-13 19:47
'''

class Solution:
    # @param n: an integer
    # @return an integer f(n)
    def fibonacci(self, n):
        # write your code here
        if n <= 1:
            return 0;
        f1, f2 = 0, 1
        for i in range(2,n):
            f1, f2 = f2, f1+f2
        return f2
