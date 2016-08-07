# coding:utf-8
'''
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/merge-two-sorted-lists
@Language: Python
@Datetime: 16-04-26 02:36
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
    @param two ListNodes
    @return a ListNode
    """
    def mergeTwoLists(self, l1, l2):
        dum = ListNode(-1)
        cur = dum
        while l1 and l2:
            if l1.val < l2.val:
                cur.next = ListNode(l1.val)
                cur, l1 = cur.next, l1.next
            else:
                cur.next = ListNode(l2.val)
                cur, l2 = cur.next, l2.next
        while l1:
            cur.next = ListNode(l1.val)
            cur, l1 = cur.next, l1.next
        while l2:
            cur.next = ListNode(l2.val)
            cur, l2 = cur.next, l2.next
            
        return dum.next