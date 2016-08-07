# coding:utf-8
'''
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/n-queens
@Language: Python
@Datetime: 16-07-05 23:47
'''

class Solution:
    """
    Get all distinct N-Queen solutions
    @param n: The number of queens
    @return: All distinct solutions
    """
    def solveNQueens(self, n):
        def show(one, n):
            strs = []
            for i in one:
                x = '.' * i + 'Q' + '.'* (n-1-i)
                strs.append(x)
            return strs
        def valid(one, p, i):
            for j in range(p):
                if one[j]== i or abs(one[j]-one[p]) == abs(j-p):
                    return False
            return True
        def dfs(p, n, one, res):
            if p == n:
                res.append(show(one, n))
                return
            for i in range(n):
                one[p] = i
                if valid(one, p, i):
                    dfs(p+1, n, one, res)
            return
        one = [-1] * n
        res = []
        for i in range(n):
            one[0] = i
            dfs(1, n, one, res)
        return res
