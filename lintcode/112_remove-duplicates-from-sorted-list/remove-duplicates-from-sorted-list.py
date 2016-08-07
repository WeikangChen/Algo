# coding:utf-8
'''
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/remove-duplicates-from-sorted-list
@Language: Python
@Datetime: 16-04-24 21:40
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
    @param head: A ListNode
    @return: A ListNode
    """
    def deleteDuplicates(self, head):
        if not head:
            return
        pre = head
        cur = head.next
        while cur:
            while cur and cur.val == pre.val:
                cur = cur.next
            pre.next = cur
            if cur:
                pre, cur = cur, cur.next
        return head