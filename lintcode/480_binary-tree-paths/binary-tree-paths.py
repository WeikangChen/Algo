# coding:utf-8
'''
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/binary-tree-paths
@Language: Python
@Datetime: 16-04-26 01:15
'''

"""
Definition of TreeNode:
class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left, self.right = None, None
"""


class Solution:
    # @param {TreeNode} root the root of the binary tree
    # @return {List[str]} all root-to-leaf paths
    def binaryTreePaths(self, root):
        def dfs(cur, one, res):
            if cur:
                one.append(cur.val)
                if not cur.left and not cur.right:
                    res.append('->'.join(map(str, one)))
                else:
                    dfs(cur.left, one, res)
                    dfs(cur.right, one, res)
                one.pop()
        res = []
        one = []
        dfs(root, one, res)
        return res
