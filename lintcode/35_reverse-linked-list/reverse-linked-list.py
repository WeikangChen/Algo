# coding:utf-8
'''
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/reverse-linked-list
@Language: Python
@Datetime: 16-07-02 23:27
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
    @param head: The first node of the linked list.
    @return: You should return the head of the reversed linked list. 
                  Reverse it in-place.
    """
    def reverse(self, head):
        if not head:
            return None
        pre, cur = None, head
        while cur:
            aft = cur.next
            cur.next = pre
            pre, cur = cur, aft
        return pre
            
    