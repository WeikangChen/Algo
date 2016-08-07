# coding:utf-8
'''
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/implement-queue-by-two-stacks
@Language: Python
@Datetime: 16-05-07 02:01
'''

class MyQueue:

    def __init__(self):
        self.stack1 = []
        self.stack2 = []

    def push(self, element):
        self.stack1.append(element)

    def top(self):
        if not self.stack2:
            while self.stack1:
                self.stack2.append(self.stack1.pop())
        return self.stack2[-1]

    def pop(self):
        if not self.stack2:
            while self.stack1:
                self.stack2.append(self.stack1.pop())
        return self.stack2.pop()