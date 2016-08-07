# coding:utf-8
'''
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/flatten-binary-tree-to-linked-list
@Language: Python
@Datetime: 16-05-03 03:00
'''

"""
Definition of TreeNode:
class TreeNode:
    def __init__(self, val):
        this.val = val
        this.left, this.right = None, None
"""
class Solution:
    # @param root: a TreeNode, the root of the binary tree
    # @return: nothing
    def flatten(self, root):
        def util(cur, pre):
            if not cur:
                return
            util(cur.right, pre)
            util(cur.left, pre)
            cur.left = None
            cur.right = pre[0] if pre else None
            pre[:] = [cur]
        pre = []
        util(root, pre)