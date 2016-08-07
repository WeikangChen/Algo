# coding:utf-8
'''
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/triangle
@Language: Python
@Datetime: 16-04-24 21:22
'''

class Solution:
    """
    @param triangle: a list of lists of integers.
    @return: An integer, minimum path sum.
    """
    def minimumTotal(self, triangle):
        arr = triangle[-1]
        n = len(triangle)
        for i in range(n-1, 0, -1):
            for j in range(i):
                arr[j] = triangle[i-1][j] + min(arr[j], arr[j+1])
        return arr[0]