# coding:utf-8
'''
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/count-and-say
@Language: Python
@Datetime: 16-05-14 17:51
'''

class Solution:
    # @param {int} n the nth
    # @return {string} the nth sequence
    def countAndSay(self, n):
        def helper(pre):
            l = len(pre)
            res = ""
            i = 0
            while i < l:
                cur = pre[i]
                cnt = 1
                while i+1 < l and pre[i+1] == cur:
                    cnt += 1
                    i += 1
                res += str(cnt) + str(cur)
                i += 1
            return res
        if n < 0:
            return ""
        res = "1"
        for i in range(n-1):
            res = helper(res)
        return res
            