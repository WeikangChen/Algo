# coding:utf-8
'''
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/lowest-common-ancestor
@Language: Python
@Datetime: 16-05-04 01:41
'''

"""
Definition of TreeNode:
class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left, self.right = None, None
"""
import copy
class Solution:
    """
    @param root: The root of the binary search tree.
    @param A and B: two nodes in a Binary.
    @return: Return the least common ancestor(LCA) of the two nodes.
    """
    def lowestCommonAncestor(self, root, A, B):
        if not root:
            return None
        lc = self.lowestCommonAncestor(root.left, A, B)
        rc = self.lowestCommonAncestor(root.right, A, B)
        if lc and rc:
            return root
        if not lc and not rc:
            return root if root is A or root is B else None
        if not lc:
            return root if root is A or root is B else rc
        if not rc:
            return root if root is A or root is B else lc
