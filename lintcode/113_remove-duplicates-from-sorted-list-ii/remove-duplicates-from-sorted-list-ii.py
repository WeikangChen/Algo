# coding:utf-8
'''
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/remove-duplicates-from-sorted-list-ii
@Language: Python
@Datetime: 16-07-02 21:54
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
        dum = ListNode(0)
        dum.next = head
        pre, cur = dum, head
        while cur:
            if cur.next and cur.val == cur.next.val: 
                cur = cur.next
                while cur.next and cur.val == cur.next.val: 
                    cur = cur.next
                pre.next = cur = cur.next
            else:
                pre, cur = cur, cur.next
        return dum.next