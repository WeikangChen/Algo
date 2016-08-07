# coding:utf-8
'''
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/binary-tree-zigzag-level-order-traversal
@Language: Python
@Datetime: 16-05-04 00:37
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
    @return: A list of list of integer include 
             the zig zag level order traversal of its nodes' values
    """
    def zigzagLevelOrder(self, root):
        if not root:
            return []
        que = [root]
        res = []
        lvl = []
        cnt = 1
        rev = False
        while que:
            cur = que.pop(0)
            cnt -= 1
            lvl.append(cur.val)
            if cur.left:
                que.append(cur.left)
            if cur.right:
                que.append(cur.right)
            if cnt == 0:
                cnt = len(que)
                if rev: lvl.reverse() 
                rev = not rev
                res.append(lvl[:])
                lvl[:] = []
        return res