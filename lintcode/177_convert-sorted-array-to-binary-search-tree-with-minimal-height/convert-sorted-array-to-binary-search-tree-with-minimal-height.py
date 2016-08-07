# coding:utf-8
'''
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/convert-sorted-array-to-binary-search-tree-with-minimal-height
@Language: Python
@Datetime: 16-05-04 00:41
'''

"""
Definition of TreeNode:
class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left, self.right = None, None
"""
class Solution:
    """
    @param A: a list of integer
    @return: a tree node
    """
    def sortedArrayToBST(self, A):
        def util(A, l, r):
            if l > r:
                return None
            if l == r:
                return TreeNode(A[l])
            m = (l + r) / 2
            cur = TreeNode(A[m])
            cur.left = util(A, l, m-1)
            cur.right = util(A, m+1, r)
            return cur
        return util(A, 0, len(A)-1)
