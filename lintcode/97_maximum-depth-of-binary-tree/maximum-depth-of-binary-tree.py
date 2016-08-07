# coding:utf-8
'''
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/maximum-depth-of-binary-tree
@Language: Python
@Datetime: 16-04-23 02:08
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
    @return: An integer
    """ 
    def maxDepth(self, root):
        return 0 if root is None else max(self.maxDepth(root.left), self.maxDepth(root.right)) + 1