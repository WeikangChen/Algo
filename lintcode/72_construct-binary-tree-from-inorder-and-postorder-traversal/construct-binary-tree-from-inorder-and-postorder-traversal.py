# coding:utf-8
'''
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/construct-binary-tree-from-inorder-and-postorder-traversal
@Language: Python
@Datetime: 16-05-04 01:24
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
    @param inorder : A list of integers that inorder traversal of a tree
    @param postorder : A list of integers that postorder traversal of a tree
    @return : Root of a tree
    """
    def buildTree(self, inorder, postorder):
        def util(inorder, postorder, hs, p, l, r):
            if l > r:
                return None
            val = postorder[p]
            cur = TreeNode(val)
            m = hs[val]
            cur.left = util(inorder, postorder, hs, p-r+m-1, l, m-1)
            cur.right = util(inorder, postorder, hs, p-1, m+1, r)
            return cur
        n = len(inorder)
        hs = {}
        for i in range(n):
            hs[inorder[i]] = i
        return util(inorder, postorder, hs, n-1, 0, n-1)