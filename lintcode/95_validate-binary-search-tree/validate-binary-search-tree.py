# coding:utf-8
'''
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/validate-binary-search-tree
@Language: Python
@Datetime: 16-04-17 19:11
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
    @return: True if the binary tree is BST, or false
    """
    def isValidBST(self, root):
        stk = []
        pre, cur = None, root
        while stk or cur:
            if cur:
                stk.append(cur)
                cur = cur.left
            else:
                cur = stk.pop()
                if pre and pre.val >= cur.val:
                    return False
                pre, cur = cur, cur.right

        return True