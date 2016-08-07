# coding:utf-8
'''
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/fizz-buzz
@Language: Python
@Datetime: 16-04-22 14:26
'''

class Solution:
    """
    @param n: An integer as description
    @return: A list of strings.
    For example, if n = 7, your code should return
        ["1", "2", "fizz", "4", "buzz", "fizz", "7"]
    """
    def fizzBuzz(self, n):
        def fun(i):
            if i % 15 == 0:
                return "fizz buzz"
            elif i % 5 == 0:
                return "buzz"
            elif i % 3 == 0:
                return "fizz"
            else:
                return str(i)
        return map(fun, range(1, n+1))