# coding:utf-8
'''
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/binary-tree-level-order-traversal
@Language: Python
@Datetime: 16-05-04 00:18
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
    @return: Level order in a list of lists of integers
    """
    def levelOrder(self, root):
        if not root:
            return []
        que = [root]
        res = []
        lvl = []
        cnt = 1
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
                res.append(lvl[:])
                lvl[:] = []
        return res