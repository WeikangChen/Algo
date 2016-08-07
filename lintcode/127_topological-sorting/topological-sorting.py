# coding:utf-8
'''
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/topological-sorting
@Language: Python
@Datetime: 16-05-05 03:15
'''

# Definition for a Directed graph node
# class DirectedGraphNode:
#     def __init__(self, x):
#         self.label = x
#         self.neighbors = []


class Solution:
    """
    @param graph: A list of Directed graph node
    @return: A list of graph nodes in topological order.
    """
    def topSort(self, graph):
        def util(node, graph, visited, res):
            visited[node.label] = True
            for n in node.neighbors:
                if not visited[n.label]:
                    util(n, graph, visited, res)
            res.append(node)
        v_size = len(graph)
        visited = [False] * v_size
        res = []
        for node in graph:
            if not visited[node.label]:
                util(node, graph, visited, res)
        return res[::-1]