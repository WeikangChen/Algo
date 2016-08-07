# coding:utf-8
'''
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/nth-to-last-node-in-list
@Language: Python
@Datetime: 16-07-02 21:46
'''

"""
Definition of ListNode
class ListNode(object):

    def __init__(self, val, next=None):
        self.val = val
        self.next = next
"""


class Solution:
    """
    @param head: The first node of linked list.
    @param n: An integer.
    @return: Nth to last node of a singly linked list.
    """
    def nthToLast(self, head, n):
        slow = fast = head
        for i in range(n):
            fast = fast.next
        while fast:
            slow, fast = slow.next, fast.next;
        return slow