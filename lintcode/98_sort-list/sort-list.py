# coding:utf-8
'''
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/sort-list
@Language: Python
@Datetime: 16-07-02 21:35
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
    @return: You should return the head of the sorted linked list,
                  using constant space complexity.
    """
    def sortList(self, head):
        def merge(l1, l2):
            dum = ListNode(0)
            cur = dum
            while l1 and l2:
                if l1.val < l2.val:
                    cur.next, l1 = l1, l1.next
                else:
                    cur.next, l2 = l2, l2.next
                cur = cur.next
            if l1:
                cur.next = l1
            if l2:
                cur.next = l2
            return dum.next
            
        if not head or not head.next:
            return head
        slow, fast = head, head.next.next
        while fast:
            slow, fast = slow.next, fast.next
            if fast:
                fast = fast.next
        l1, l2 = head, slow.next
        slow.next = None
        l1 = self.sortList(l1)
        l2 = self.sortList(l2)
        return merge(l1, l2)
        
            