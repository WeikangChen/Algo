# coding:utf-8
'''
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/plus-one
@Language: Python
@Datetime: 16-07-24 14:26
'''

class Solution:
    # @param {int[]} digits a number represented as an array of digits
    # @return {int[]} the result
    def plusOne(self, digits):
        res = []
        car = 1
        for d in digits[::-1]:
            tmp = d + car
            res.append(tmp % 10)
            car = tmp / 10
        if car:
            res.append(1)
        return list(reversed(res))