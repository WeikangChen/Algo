# coding:utf-8
'''
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/clone-graph
@Language: Python
@Datetime: 16-07-24 21:32
'''

# Definition for a undirected graph node
# class UndirectedGraphNode:
#     def __init__(self, x):
#         self.label = x
#         self.neighbors = []
class Solution:
    # @param node, a undirected graph node
    # @return a undirected graph node
    def __init__(self):
        self.dict = {}
        
    def cloneGraph(self, node):
        if not node: return None
        
        cp_head = UndirectedGraphNode(node.label)
        stk = [node]
        hs = {node:cp_head}
        
        while stk:
            cur = stk.pop() 
            cp_cur = hs[cur]
            for one in cur.neighbors:
                if one not in hs:
                    stk.append(one)
                    hs[one] = UndirectedGraphNode(one.label)
                cp_cur.neighbors.append(hs[one])
        return cp_head
        