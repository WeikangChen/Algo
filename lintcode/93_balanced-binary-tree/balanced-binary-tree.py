# coding:utf-8
'''
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/balanced-binary-tree
@Language: Python
@Datetime: 16-04-22 14:45
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
    @param root: The root of binary tree.
    @return: True if this Binary tree is Balanced, or false.
    """
    def isBalanced(self, root):
        def helper(cur):
            if cur is None:
                return 0
            l = helper(cur.left)
            r = helper(cur.right)
            if l < 0 or r < 0 or abs(l-r) > 1:
                return -1
            return max(l, r) + 1
        return helper(root) >= 0
            
       