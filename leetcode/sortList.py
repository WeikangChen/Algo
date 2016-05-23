#Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    # @param head, a ListNode
    # @return a ListNode
    def sortList(self, head):
        if not head or not head.next:
            return head
        a, b = self.split(head)
        a = self.sortList(a)
        b = self.sortList(b)
        return self.merge(a, b)

    def split(self, head):
        l1 = head
        l2 = head.next.next
        while l2 and l2.next:
            l1 = l1.next
            l2 = l2.next.next
        l2 = l1.next
        l1.next = None
        return (head, l2)

    def merge(self, l1, l2):
        if not l1: return l2
        if not l2: return l1

        if l1.val < l2.val:
            l1.next = self.merge(l1.next, l2)
            return l1
        else:
            l2.next = self.merge(l1, l2.next)
            return l2

def ArrayToList(arr):
    dum = ListNode(-1)
    pre = dum

    for a in arr:
        pre.next = ListNode(a)
        pre = pre.next
    return dum.next
