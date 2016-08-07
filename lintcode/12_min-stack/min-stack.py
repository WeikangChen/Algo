# coding:utf-8
'''
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/min-stack
@Language: Python
@Datetime: 16-04-29 00:31
'''

class MinStack(object):

    def __init__(self):
        self.stk1 = []
        self.stk2 = []

    def push(self, number):
        self.stk1.append(number)
        self.stk2.append(number if not self.stk2 else min(self.stk2[-1], number))

    def pop(self):
        self.stk2.pop()
        return self.stk1.pop()

    def min(self):
        return self.stk2[-1] if self.stk2 else None