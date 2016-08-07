# coding:utf-8
'''
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/remove-node-in-binary-search-tree
@Language: Python
@Datetime: 16-04-17 19:54
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
    @param root: The root of the binary search tree.
    @param value: Remove the node with given value.
    @return: The root of the binary search tree after removal.
    """
    def removeNode(self, root, value):
        def helper(cur, value):
            if cur is None:
                return None
            l = helper(cur.left, value)
            r = helper(cur.right, value)
            if cur.val == value:
                if l:
                    rr = l
                    while rr.right:
                        rr = rr.right
                    rr.right = r
                    return l
                else:
                    return r
            cur.left, cur.right = l, r 
            return cur
        return helper(root, value)
