# coding:utf-8
'''
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/reverse-pairs
@Language: Python
@Datetime: 16-05-03 00:03
'''

class Solution:
    # @param {int[]} A an array
    # @return {int} total of reverse pairs
    def reversePairs(self, A):
        def merge(arr_l, arr_r):
            m, n = len(arr_l), len(arr_r)
            i = j = 0
            arr_a = []
            rev_m = 0
            while i < m and j < n:
                if arr_l[i] <= arr_r[j]:
                    arr_a.append(arr_l[i])
                    i += 1
                else:
                    arr_a.append(arr_r[j])
                    j += 1
                    rev_m += m - i
            while i < m:
                arr_a.append(arr_l[i])
                i += 1
            while j < n:
                arr_a.append(arr_r[j])
                j += 1
            return arr_a, rev_m

        def util(A):
            n = len(A)
            if n <= 1:
                return A, 0
            m = n / 2;
            arr_l, rev_l = util(A[:m])
            arr_r, rev_r = util(A[m:])
            arr_a, rev_m = merge(arr_l, arr_r)
            return arr_a, rev_l + rev_r + rev_m
        
        sortedA, res = util(A)
        return res