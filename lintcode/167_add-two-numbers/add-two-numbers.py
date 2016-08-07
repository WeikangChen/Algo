# coding:utf-8
'''
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/add-two-numbers
@Language: Python
@Datetime: 16-07-02 21:43
'''

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    # @param l1: the first list
    # @param l2: the second list
    # @return: the sum list of l1 and l2 
    def addLists(self, l1, l2):
        dum = ListNode(0)
        cur = dum
        car = 0
        while l1 or l2 or car:
            tmp = car
            if l1:
                tmp += l1.val
                l1 = l1.next
            if l2:
                tmp += l2.val
                l2 = l2.next
            cur.next = ListNode(tmp % 10)
            cur = cur.next
            car = tmp / 10
        return dum.next