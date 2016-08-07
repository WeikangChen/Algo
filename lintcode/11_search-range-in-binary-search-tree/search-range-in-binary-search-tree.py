# coding:utf-8
'''
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/search-range-in-binary-search-tree
@Language: Python
@Datetime: 16-04-24 21:16
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
    @param k1 and k2: range k1 to k2.
    @return: Return all keys that k1<=key<=k2 in ascending order.
    """
    def searchRange(self, root, k1, k2):
        res = []
        stk = []
        cur = root
        while stk or cur:
            if cur:
                stk.append(cur)
                cur = cur.left
            else:
                cur = stk.pop()
                val = cur.val
                if val > k2:
                    break
                if val >= k1:
                    res.append(val)
                cur = cur.right
        return res